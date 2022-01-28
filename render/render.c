/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:47:08 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/08 16:50:06 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_correctdist(t_data *data, t_mlx *mlx, float deg)
{
	int	count;

	data->dist *= cosf(ft_deg2rad(deg - mlx->player.view_direction));
	data->dist = (mlx->cube_size / data->dist) * ((mlx->win.width / 2)
			/ tanf(ft_deg2rad(mlx->player.fov / 2.f)));
	count = 0;
	while (count < data->sp_count)
	{
		if (data->sp_data[count].dist >= 0.00000001f)
		{
			data->sp_data[count].dist *= cosf(ft_deg2rad(deg
						- mlx->player.view_direction));
			data->sp_data[count].dist
				= (data->sp_data[count].sprite->displayimg->height
					/ data->sp_data[count].dist) * ((mlx->win.width / 2)
					/ tanf(ft_deg2rad(mlx->player.fov / 2.f)));
		}
		count++;
	}
}

static void	ft_sortsprites(t_data *data)
{
	t_spritedata	buf;
	int				count;

	count = 1;
	while (count < data->sp_count)
	{
		if (data->sp_data[count].dist < data->sp_data[count - 1].dist)
		{
			buf = data->sp_data[count - 1];
			data->sp_data[count - 1] = data->sp_data[count];
			data->sp_data[count] = buf;
		}
		else if (count < data->sp_count - 1 && data->sp_data[count].dist
			> data->sp_data[count + 1].dist)
		{
			buf = data->sp_data[count + 1];
			data->sp_data[count + 1] = data->sp_data[count];
			data->sp_data[count] = buf;
		}
		else
			count++;
	}
}

static t_spritedata	*ft_newdata(t_data *goal, t_data *other)
{
	t_spritedata	*newdata;

	newdata = (t_spritedata *)ft_calloc(sizeof(t_spritedata)
			* (goal->sp_count + other->sp_count), 1);
	if (!newdata)
	{
		if (goal->dist > other->dist)
		{
			if (goal->sp_data)
				free(goal->sp_data);
			*goal = *other;
		}
		if (other->sp_data)
			free(other->sp_data);
		return (NULL);
	}
	return (newdata);
}

static void	ft_handlesprites(t_data *goal, t_data *other)
{
	t_spritedata	*newdata;
	int				size;
	float			dist;

	dist = goal->dist;
	if (dist > other->dist)
		dist = other->dist;
	newdata = ft_newdata(goal, other);
	if (!newdata)
		return ;
	size = ft_setnewdata(newdata, goal, other, dist);
	if (goal->sp_data)
		free(goal->sp_data);
	if (other->sp_data)
		free(other->sp_data);
	if (goal->dist > other->dist)
		*goal = *other;
	goal->sp_count = size;
	goal->sp_data = newdata;
	ft_sortsprites(goal);
}

void	ft_rendergame(t_mlx *mlx)
{
	int		count;
	float	deg;
	t_line	ray;
	t_data	data[2];

	count = 1;
	deg = mlx->player.view_direction - mlx->player.fov / 2.f;
	while (count <= mlx->imgs[0]->width)
	{
		deg = ft_fix(deg);
		ray.m = tanf(ft_deg2rad(deg));
		ray.t = mlx->player.y_coord - (ray.m * mlx->player.x_coord);
		ft_setdata(deg, &ray, mlx, data);
		ft_handlesprites(&data[0], &data[1]);
		ft_correctdist(&data[0], mlx, deg);
		ft_drawvertline(mlx, mlx->win.width - count, data[0], data[0].img);
		ft_drawspritevert(mlx, data[0], mlx->win.width - count);
		if (data[0].sp_data)
			free(data[0].sp_data);
		deg += mlx->player.fov / mlx->win.width;
		count++;
	}
}
