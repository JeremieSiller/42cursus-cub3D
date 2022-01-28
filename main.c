/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:28:32 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/08 16:47:08 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "validate/validate.h"
#include "render/render.h"
#include "sprite/sprite.h"

int	cross_hook(int key, void *param)
{
	exit(0);
	(void)param;
	(void)key;
	return (1);
}

static void	ft_docf(t_mlx *mlx)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < mlx->win.height)
	{
		x = 0;
		while (x < mlx->win.width)
		{
			if (y <= mlx->win.height / 2)
				color = ft_tcolour2uint(mlx->file.clr[ROOF]);
			else
				color = ft_tcolour2uint(mlx->file.clr[FLOOR]);
			ft_putpixelimg(mlx->imgs[0], x, y, color);
			x++;
		}
		y++;
	}
}

static void	ft_move(t_mlx *mlx)
{
	if (mlx->file.map.arr[(int)(mlx->player.x_coord + mlx->player.x_move)
		/ mlx->cube_size][abs((int)(mlx->player.y_coord + mlx->player.y_move)
			/ mlx->cube_size)] == '1')
		return ;
	mlx->player.x_coord += mlx->player.x_move;
	mlx->player.y_coord += mlx->player.y_move;
}

int	render_next_frame(t_mlx *mlx)
{
	if (mlx->menu == GAME_SCREEN)
	{
		update_map(&mlx->file.map, mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win.win_ptr,
			mlx->imgs[0]->img_ptr, 0, 0);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win.win_ptr,
			mlx->map->img_ptr, 0, 0);
		if (mlx->fcount % 4 == 0)
		{
			mlx->sprites[SP_COIN]->current_frame++;
			if (mlx->sprites[SP_COIN]->current_frame
				>= mlx->sprites[SP_COIN]->frame_count)
				mlx->sprites[SP_COIN]->current_frame = 0;
			ft_setframe(mlx->sprites[SP_COIN]);
		}
		ft_docf(mlx);
		if (mlx->player.move)
			ft_move(mlx);
		ft_rendergame(mlx);
		mlx->fcount++;
		return (0);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win.win_ptr,
		mlx->imgs[0]->img_ptr, 0, 0);
	return (ft_mainscreen(mlx));
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (reader(&mlx, argc, argv))
		return (1);
	if (init_mlx_stuff(&mlx))
		return (1);
	ft_docf(&mlx);
	ft_rendergame(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win.win_ptr,
		mlx.imgs[0]->img_ptr, 0, 0);
	ft_mainscreen(&mlx);
	mlx_hook(mlx.win.win_ptr, 6, (1L << 6), mouse_hook, &mlx);
	mlx_hook(mlx.win.win_ptr, 2, (1L << 0), key_press_hook, &mlx);
	mlx_hook(mlx.win.win_ptr, 17, (1L << 0), cross_hook, &mlx);
	mlx_key_hook(mlx.win.win_ptr, key_hook, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, render_next_frame, &mlx);
	mlx_mouse_hide();
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
