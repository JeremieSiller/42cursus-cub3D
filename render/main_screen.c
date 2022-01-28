/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:52:31 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/03 20:03:21 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*
** 0 Is on the edge, if you want the next one add FONT_WIDTH / 1.4
** I manually set the FONT_HEIGHT TO 9, so 0 is 
** FONT_HEIGHT and next one is FONT_HEIGHT * 2
** USE THIS FUNCTION IT AUTOCORRECTS POSITIONS :D
*/
static void	ft_putcenteredstring(t_mlx *mlx,
		int pos[2], const char *str, unsigned int color)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win.win_ptr,
		pos[0] - (FONT_WIDTH / 1.4 * (ft_strlen(str) / 2)),
		pos[1] + (FONT_HEIGHT / 4), color, (char *)str);
}

int	ft_mainscreen(t_mlx *mlx)
{
	int	x;
	int	y;

	if (ft_getpixelimg(mlx->imgs[5], 0, 0) == 0x00000000)
	{
		y = 0;
		while (y < mlx->imgs[5]->height)
		{
			while (x < mlx->imgs[5]->width)
			{
				ft_putpixelimg(mlx->imgs[5],
					x, y, ft_argb2uint(200, 96, 96, 96));
				++x;
			}
			x = 0;
			++y;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win.win_ptr,
		mlx->imgs[5]->img_ptr, 0, 0);
	ft_putcenteredstring(mlx, (int [2]){640, 360},
		"Press ESC or click the red cross to kill the game.", 0x00FFFFFF);
	ft_putcenteredstring(mlx, (int [2]){640, 360
		+ FONT_HEIGHT}, "Press return to continue.", 0x00FFFFFF);
	return (0);
}
