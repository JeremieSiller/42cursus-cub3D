/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:19:42 by jsiller           #+#    #+#             */
/*   Updated: 2021/09/28 16:41:55 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "img.h"

static void	set_hash(int x, int y, t_img *img, char hash[8])
{
	ft_memset(hash, 0, sizeof(*hash) * 8);
	if (x > 0)
		hash[0] = 1;
	if (y > 0)
		hash[1] = 1;
	if (x > 0 && y > 0)
		hash[2] = 1;
	if (x + 1 < img->width)
		hash[3] = 1;
	if (y + 1 < img->height)
		hash[4] = 1;
	if (y + 1 < img->height && x + 1 < img->width)
		hash[5] = 1;
	if (y + 1 < img->height && x > 0)
		hash[6] = 1;
	if (y > 0 && x + 1 < img->width)
		hash[7] = 1;
}

static void	set_arr(int x, int y, t_img *img, int arr[8])
{
	ft_memset(arr, 0xFFFFFFFF, sizeof(*arr) * 8);
	if (x > 0)
		arr[0] = ft_getpixelimg(img, x - 1, y);
	if (y > 0)
		arr[1] = ft_getpixelimg(img, x, y - 1);
	if (x > 0 && y > 0)
		arr[2] = ft_getpixelimg(img, x - 1, y - 1);
	if (x + 1 < img->width)
		arr[3] = ft_getpixelimg(img, x + 1, y);
	if (y + 1 < img->height)
		arr[4] = ft_getpixelimg(img, x, y + 1);
	if (y + 1 < img->height && x + 1 < img->width)
		arr[5] = ft_getpixelimg(img, x + 1, y + 1);
	if (y + 1 < img->height && x > 0)
		arr[6] = ft_getpixelimg(img, x - 1, y + 1);
	if (y > 0 && x + 1 < img->width)
		arr[7] = ft_getpixelimg(img, x + 1, y - 1);
}

int	most_use(int arr[8], char hash[8])
{
	int		i;
	int		j;
	int		ret;
	int		max;
	int		count;

	i = 0;
	while (i < 8)
	{
		j = i + 1;
		count = 0;
		while (j < 8)
		{
			if (arr[i] == arr[j] && hash[j] == 1)
				count++;
			j++;
		}
		if (i == 0 || count > max)
		{
			ret = arr[i];
			max = count;
		}
		i++;
	}
	return (ret);
}

int	most_used_color(t_img *img, int x, int y)
{
	int		arr[8];
	char	hash[8];

	set_arr(x, y, img, arr);
	set_hash(x, y, img, hash);
	return (most_use(arr, hash));
}

/*
** takes an image and a single pointer of the same size as 
** the image which only contains 1 and 0. 
** Every spot in the image which is 0 in arr will be calculated 
** (depending on the most used colour around it)
*/
t_img	*interpolate(t_img *img, char *arr)
{
	int	x;
	int	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			if (arr[(img->width * x) + y] == 0)
			{
				ft_putpixelimg(img, x, y, most_used_color(img, x, y));
			}
			y++;
		}
		x++;
	}
	return (img);
}
