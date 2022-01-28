/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:25:38 by nschumac          #+#    #+#             */
/*   Updated: 2021/09/26 18:33:44 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../render/render.h"

static unsigned int	ft_getcolor(t_img *org, int x, int y, float p)
{
	unsigned int	color[7];
	float			acX;
	float			acY;

	acX = x / p;
	acY = y / p;
	color[0] = *(unsigned int *)(org->data.data_addr
			+ (unsigned int)((int)acY * org->data.size_line
				+ (int)acX * (org->data.bpp / 8)));
	return (color[0]);
}

static void	ft_change(t_img *ret, t_img *org, float p)
{
	int				x;
	int				y;

	x = 0;
	while (x < ret->width)
	{
		y = 0;
		while (y < ret->height)
		{
			ft_putpixelimg(ret, x, y, ft_getcolor(org, x, y, p));
			y++;
		}
		x++;
	}
}

/*
** This is a cheap and inaccurate resize
** where the image only duplicates/ leaves out certain pixels
** Linear interpolation would be better but i didnt manage to do it :/
*/
t_img	*ft_resize(void	*mlx, t_img *org, float p)
{
	t_img	*ret;

	ret = ft_new_mlx_img(mlx, org->width * p, org->height * p);
	ret->x = 0;
	ret->y = 0;
	if (!ret)
		return (NULL);
	ft_change(ret, org, p);
	return (ret);
}
