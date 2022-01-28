/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:27:05 by jsiller           #+#    #+#             */
/*   Updated: 2021/10/04 16:06:46 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "img.h"

/*
** returns hypotenuse of the two cathetes x and y
*/
int	get_max_size(int x, int y)
{
	return (roundf(sqrtf((float)((x * x) + (y * y)))) + 1);
}

/*
** calculates the new point of x and y when beeing rotated
*/
void	calculate_new_x_y(int x, int y, t_point *p, float degree)
{
	p->x = roundf(((cosf(ft_deg2rad(degree)) * (float)x)
				- (sinf(ft_deg2rad(degree)) * (float)y)));
	p->y = roundf((sinf(ft_deg2rad(degree)) * (float)x
				+ cosf(ft_deg2rad(degree)) * (float)y));
}

t_img	*calculate_rotation(t_img *img, t_img *ret, float degree, char *arr)
{
	int		x;
	int		y;
	t_point	p;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			calculate_new_x_y(x - img->width / 2,
				img->height / 2 - y, &p, degree);
			ft_putpixelimg(ret, p.x + ret->width / 2,
				p.y + ret->height / 2, ft_getpixelimg(img, x, y));
			arr[(ret->width * (p.x + ret->width / 2))
				+ (p.y + ret->height / 2)] = 1;
			y++;
		}
		x++;
	}
	return (interpolate(ret, arr));
}

/*
** rotates an image to degree and returns a NEW! image
** which needs to be checked for NULL and freed.
** Image will be resized to a square 
** with the length of the diagonale of the input image.
*/
t_img	*rotate(t_img *img, float degree, t_mlx *mlx)
{
	t_img	*ret;
	char	*arr;
	int		x;

	ret = ft_new_mlx_img(mlx->mlx_ptr, get_max_size(img->height, img->width),
			get_max_size(img->height, img->width));
	if (!ret)
		return (NULL);
	arr = ft_calloc(sizeof(*arr), ret->width * ret->height);
	if (!arr)
	{
		ft_free_allimg(mlx, mlx->mlx_ptr, img);
		return (NULL);
	}
	x = 0;
	ft_memset(ret->data.data_addr, 0xFFFFFFFF,
		ret->width * ret->height * (ret->data.bpp / 8));
	ret = calculate_rotation(img, ret, degree, arr);
	free(arr);
	return (ret);
}
