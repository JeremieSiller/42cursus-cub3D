/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:47:31 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/08 16:51:02 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../render/render.h"
#include "../validate/validate.h"

int	mouse_hook(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	y = 0;
	if (mlx->menu == GAME_SCREEN)
	{
		mlx->player.view_direction += 0.02 * (mlx->win.width / 2 - x);
		mlx->player.view_direction = ft_fix(mlx->player.view_direction);
		mlx_mouse_move(mlx->win.win_ptr,
			mlx->win.width / 2, mlx->win.height / 2);
	}
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (mlx->menu == MAIN_SCREEN && keycode == 36)
	{
		mlx->menu = GAME_SCREEN;
		mlx_mouse_hide();
		return (0);
	}
	if (keycode == KEY_ESC)
	{
		if (mlx->menu == GAME_SCREEN)
		{
			mlx->menu = MAIN_SCREEN;
			mlx_mouse_show();
		}
		else if (mlx->menu == MAIN_SCREEN)
			exit(0);
	}
	if (keycode == mlx->player.keycode)
		mlx->player.move = 0;
	return (0);
}

static void	check_movement_keys(int keycode, t_mlx *mlx, float ek[2])
{
	if ((mlx->player.view_direction >= 180.f && (keycode == KEY_W
				|| keycode == KEY_S)) || ((mlx->player.view_direction < 90.f
				|| mlx->player.view_direction >= 270.f)
			&& (keycode == KEY_A || keycode == KEY_D)))
	{
		ek[0] *= -1;
		ek[1] *= -1;
	}
	mlx->player.keycode = keycode;
	if (keycode == KEY_W || keycode == KEY_D)
	{
		mlx->player.x_move = ek[0] * mlx->cube_size / 20.f;
		mlx->player.y_move = ek[1] * mlx->cube_size / 20.f;
		mlx->player.move = 1;
	}
	if (keycode == KEY_S || keycode == KEY_A)
	{
		mlx->player.x_move = ek[0] * -mlx->cube_size / 20.f;
		mlx->player.y_move = ek[1] * -mlx->cube_size / 20.f;
		mlx->player.move = 1;
	}
}

static void	arrow_view(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_RIGHT)
	{
		mlx->player.view_direction -= 2;
		mlx->player.view_direction = ft_fix(mlx->player.view_direction);
		mlx->player.move = 0;
	}
	else if (keycode == KEY_LEFT)
	{
		mlx->player.view_direction += 2;
		mlx->player.view_direction = ft_fix(mlx->player.view_direction);
		mlx->player.move = 0;
	}
}

int	key_press_hook(int keycode, t_mlx *mlx)
{
	t_line	pl;
	float	ek[2];

	if (mlx->menu == GAME_SCREEN)
	{
		arrow_view(keycode, mlx);
		if (keycode == KEY_A || keycode == KEY_D)
			pl.m = tanf(ft_deg2rad(ft_fix(mlx->player.view_direction + 90.f)));
		else
			pl.m = tanf(ft_deg2rad(mlx->player.view_direction));
		pl.t = mlx->player.y_coord - (mlx->player.x_coord * pl.m);
		if (pl.m == 0.000000000)
			pl.m += 0.000000001f;
		ek[0] = (((-pl.t) / pl.m) - mlx->player.x_coord) / ft_length(((-pl.t)
					/ pl.m) - mlx->player.x_coord, 0 - mlx->player.y_coord);
		ek[1] = (0 - mlx->player.y_coord) / ft_length(((-pl.t)
					/ pl.m) - mlx->player.x_coord, 0 - mlx->player.y_coord);
		check_movement_keys(keycode, mlx, ek);
	}
	return (0);
}
