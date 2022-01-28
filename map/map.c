/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:45:41 by jsiller           #+#    #+#             */
/*   Updated: 2021/10/04 16:05:05 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../render/render.h"

#define MXSIZE 426
#define MYSIZE 240

/*
** fills img with blue blocks where a wall in map is found
*/
static void	fill_map(t_img *img, t_map *map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = -1;
	while (++x < map->x)
	{
		y = -1;
		while (++y < map->y)
		{
			i = -1;
			while (++i < map->block_size && map->arr[x][y] == '1')
			{
				j = -1;
				while (++j < map->block_size)
				{
					ft_putpixelimg(img, x * map->block_size + i,
						y * map->block_size + j, 0x000000ff);
				}
			}
		}
	}
}

/*
** copy src in img starting at coordinates x and y
** in case x or y is smaller 0 it starts in at 0 0
** in case src will extend over the limits of dest
** it will cut all overlaping pixels
*/
static void	copy_img_to_img(t_img *dest, t_img *src, int x, int y)
{
	int			i;
	int			j;
	t_colour	col;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	i = 0;
	while (i < src->width && i + x < dest->width)
	{
		j = 0;
		while (j < src->height && j + y < dest->height)
		{
			col = ft_uint2tcolour(ft_getpixelimg(src, i, j));
			if (col.a == 0xFF)
				ft_putpixelimg(dest, x + i, y + j, ft_getpixelimg(src, i, j));
			j++;
		}
		i++;
	}
}

/*
** updates the map to the current game position
** returns 1 on error 0 on proper exit
*/
int	update_map(t_map *map, t_mlx *data)
{
	t_img	*ply;

	set_img_col(data->map, map->block_size
		* map->x, map->block_size * map->y, 0x33808080);
	fill_map(data->map, map);
	ply = rotate(map->org, 180.0f - data->player.view_direction, data);
	if (!ply)
	{
		ft_free_allimg(data, data->mlx_ptr, map->org);
		ft_free_allimg(data, data->mlx_ptr, data->map);
		return (1);
	}
	copy_img_to_img(data->map, ply, data->player.x_coord
		/ (float)data->cube_size * (float)map->block_size - ply->width / 2,
		fabs(data->player.y_coord) / (float)data->cube_size
		* (float)map->block_size - ply->width / 2);
	ft_free_allimg(data, data->mlx_ptr, ply);
	return (0);
}

void	free_map(t_mlx *data)
{
	ft_free_allimg(data, data->mlx_ptr, data->file.map.org);
	ft_free_allimg(data, data->mlx_ptr, data->map);
}

/*
** creates img of map and assigns it to map pointer in mlx data
** returns 1 on error 0 on proper exit
** map needs to be freed on PROPER exit.
*/
int	create_map_img(t_map *map, t_mlx *data)
{
	t_img	*tmp;

	map->org = ft_new_xpm(data->mlx_ptr, "resources/player.xpm");
	if (!map->org)
		return (1);
	map->block_size = MYSIZE / map->y;
	if (MXSIZE / map->x < MYSIZE / map->y)
		map->block_size = MXSIZE / map->x;
	tmp = ft_resize(data->mlx_ptr, map->org,
			(float)map->block_size / (float)map->org->width);
	if (!tmp)
		ft_free_allimg(data, data->mlx_ptr, map->org);
	if (!tmp)
		return (1);
	ft_free_allimg(data, data->mlx_ptr, map->org);
	map->org = tmp;
	data->map = ft_new_mlx_img(data->mlx_ptr, map->block_size
			* map->x, map->block_size * map->y);
	if (!data->map)
	{
		ft_free_allimg(data, data->mlx_ptr, map->org);
		return (1);
	}
	update_map(map, data);
	return (0);
}
