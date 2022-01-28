/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:55:24 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/08 16:49:41 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
/*
** Overwrites a pixel with a certain color at position x, y
*/
void	ft_putpixelimg(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= img->width || y >= img->height)
		return ;
	dst = img->data.data_addr
		+ (y * img->data.size_line + x * (img->data.bpp / 8));
	*(unsigned int *)dst = color;
}

/*
** Returns the color of the pixel at position x, y of the image
*/
unsigned int	ft_getpixelimg(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->data.data_addr
		+ (y * img->data.size_line + x * (img->data.bpp / 8));
	return (*(unsigned int *)dst);
}

/*
** if (count / yp
** 	>= data.sp_data[data.sp_count].sprite->displayimg->height
** 	&& ++count)
** 	continue ;
*/
void	ft_drawspritevert(t_mlx *mlx, t_data data, int x)
{
	int				count;
	unsigned int	color;
	float			y;
	float			yp;

	while (--data.sp_count + 1)
	{
		if (data.sp_data[data.sp_count].dist <= 0.00000001f)
			continue ;
		y = mlx->win.height / 2 - (data.sp_data[data.sp_count].dist / 2);
		yp = data.sp_data[data.sp_count].dist
			/ data.sp_data[data.sp_count].sprite->displayimg->height;
		count = 0;
		while (count < data.sp_data[data.sp_count].dist)
		{
			color
				= ft_getpixelimg(data.sp_data[data.sp_count].sprite->displayimg,
					data.sp_data[data.sp_count].x, (count) / yp);
			if (ft_uint2tcolour(color).a != 0)
				ft_putpixelimg(mlx->imgs[0], x, y + count, color);
			count++;
		}
	}
}

/*
** ONlY USED BY RENDER.C
** This is Function that draws the vertical lines of the game
** by getting a direction which is either 1 NO, 2 EA, 3 SO, 4 WE
** it will take the texture and draw the pixels
** x is the current colomn of the Projection screen
*/
void	ft_drawvertline(t_mlx *mlx, int x, t_data data, int direction)
{
	int		count;
	int		y;
	float	acX;
	float	p;
	float	p_x;

	count = 0;
	y = mlx->win.height / 2;
	p = ((data.dist + 1) / mlx->imgs[direction]->height);
	p_x = (float)mlx->cube_size / (float)mlx->imgs[direction]->width;
	if (direction == 2 || direction == 4)
		acX = (abs((int)data.y) % mlx->cube_size) / p_x;
	else
		acX = ((int)data.x % mlx->cube_size) / p_x;
	if (y - data.dist / 2 < 0)
		count -= y - data.dist / 2;
	while (count < data.dist)
	{
		if (y - data.dist / 2 + count > mlx->win.height)
			break ;
		ft_putpixelimg(mlx->imgs[0], x, y + data.dist / 2 - count,
			ft_getpixelimg(mlx->imgs[direction], acX,
				(data.dist - count) / p));
		count++;
	}
}

/*
** Actual DrawLine
** draws line on image
*/
void	ft_drawline(t_img *img, t_data p1, t_data p2, unsigned int color)
{
	t_data	p1_p2;
	int		count;

	p1_p2.x = p2.x - p1.x;
	p1_p2.y = p2.y - p1.y;
	p1_p2.dist = ft_dist(p1.x, p1.y, p2.x, p2.y);
	count = 0;
	p1_p2.x /= p1_p2.dist;
	p1_p2.y /= p1_p2.dist;
	while (count < p1_p2.dist)
	{
		ft_putpixelimg(img, p1.x, p1.y, color);
		p1.x += p1_p2.x;
		p1.y += p1_p2.y;
		count++;
	}
}
