/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:11:15 by jsiller           #+#    #+#             */
/*   Updated: 2021/10/08 16:48:33 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "validate/validate.h"
#include "render/render.h"

int	error(char *str, int ret)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	return (ret);
}

/*
** reads file and initiliazes base values
*/
int	reader(t_mlx *mlx, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nexactly 1 argument needed\n", 2);
		return (1);
	}
	ft_memset(&mlx->file, 0, sizeof(t_file));
	ft_memset(&mlx->file.clr[0], -1, sizeof(t_colour));
	ft_memset(&mlx->file.clr[1], -1, sizeof(t_colour));
	mlx->file.clr[0].r = -1;
	mlx->file.clr[0].b = -1;
	ft_memset(&mlx->file.txt[0], 0, sizeof(t_texture));
	ft_memset(&mlx->file.txt[1], 0, sizeof(t_texture));
	ft_memset(&mlx->file.txt[2], 0, sizeof(t_texture));
	ft_memset(&mlx->file.txt[3], 0, sizeof(t_texture));
	if (valdiate(argv[1], &mlx->file))
		return (1);
	mlx->player.fov = 60.f;
	mlx->player.view_direction = mlx->file.player.view_direction;
	mlx->player.move = 0;
	mlx->menu = GAME_SCREEN;
	mlx->fcount = 0;
	return (0);
}

/*
** inits mlx, window, imgs, and sprites
*/
int	init_mlx_stuff(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (error("Could not create mlx", 1));
	if (!ft_create_window(mlx, 1280, 720, "test"))
		return (error("Could not create window", 1));
	if (!ft_setimages(mlx))
		return (error("Could not create image", 1));
	if (create_map_img(&(mlx->file.map), mlx) == 1)
		return (error("Could not create map_image", 1));
	mlx->player.x_coord
		= mlx->file.player.x_coord * mlx->cube_size + mlx->cube_size / 2;
	mlx->player.y_coord
		= mlx->file.player.y_coord * -mlx->cube_size - mlx->cube_size / 2;
	if (ft_setsprites(mlx) == 0)
		return (error("Could not create sprites", 2));
	return (0);
}
