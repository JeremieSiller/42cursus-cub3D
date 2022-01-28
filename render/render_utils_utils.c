/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:45:01 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/03 20:21:12 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_setcoords(float curPoint[2], t_mlx *mlx, t_data *data,
			int x_y[2])
{
	t_line		orto;
	t_line		p2s;

	p2s.m = ((-x_y[1] * mlx->cube_size - mlx->cube_size / 2)
			- mlx->player.y_coord) / ((x_y[0] * mlx->cube_size + mlx->cube_size
				/ 2) - mlx->player.x_coord);
	p2s.t = mlx->player.y_coord - p2s.m * mlx->player.x_coord;
	orto.m = -1 / p2s.m;
	orto.t = (-x_y[1] * mlx->cube_size - mlx->cube_size / 2)
		- (orto.m * (x_y[0] * mlx->cube_size + mlx->cube_size / 2));
	if (p2s.m == 0)
	{
		curPoint[0] = (x_y[0] * mlx->cube_size + mlx->cube_size / 2);
		curPoint[1] = data->ray->m * curPoint[0] + data->ray->t;
	}
	else
	{
		curPoint[0] = (orto.t - data->ray->t) / (data->ray->m - orto.m);
		curPoint[1] = orto.m * curPoint[0] + orto.t;
	}
}

/*
** (x * mlx->cube_size + mlx->cube_size / 2))
** / (-y * mlx->cube_size - mlx->cube_size / 2)
** mittelpunkt vom kasten
** orto gerade ist sozusagen mein sprite
*/
int	ft_spritecheck(t_data *data, t_mlx *mlx, int x_y[2], t_data *ret)
{
	float		curPoint[2];
	float		dist;
	static int	left[100];

	if (left[data->sp_count] == 0)
		left[data->sp_count] = 1;
	ft_setcoords(curPoint, mlx, data, x_y);
	dist = ft_dist(curPoint[0], curPoint[1], (x_y[0] * mlx->cube_size
				+ mlx->cube_size / 2), (-x_y[1] * mlx->cube_size
				- mlx->cube_size / 2));
	if (dist <= mlx->sprites[SP_COIN]->displayimg->width / 2)
	{
		ret->dist = ft_dist(curPoint[0], curPoint[1],
				mlx->player.x_coord, mlx->player.y_coord);
		ret->x = (mlx->sprites[SP_COIN]->displayimg->width / 2)
			+ (dist * left[data->sp_count]);
		if ((int)dist == 0)
			left[data->sp_count] = -1;
		else if ((int)dist + 1 >= mlx->sprites[SP_COIN]->displayimg->width / 2)
			left[data->sp_count] = 1;
		return (1);
	}
	return (0);
}

void	ft_setdata(float deg, t_line *ray, t_mlx *mlx, t_data *data)
{
	if (deg <= 90.f || deg >= 270.f)
		data[0] = ft_eastvertical(ray, mlx);
	else
		data[0] = ft_westvertical(ray, mlx);
	if (deg <= 180.f && deg >= 0.f)
		data[1] = ft_northhorizontal(ray, mlx);
	else
		data[1] = ft_southhorizontal(ray, mlx);
}

int	ft_setnewdata(t_spritedata *newdata, t_data *goal,
		t_data *other, float dist)
{
	int	rep[2];

	ft_bzero(rep, 2 * sizeof(int));
	while (++rep[0] <= goal->sp_count)
		if (goal->sp_data[rep[0] - 1].dist < dist)
			newdata[rep[0] - 1] = goal->sp_data[rep[0] - 1];
	while (rep[0] - (goal->sp_count + 1) < other->sp_count)
	{
		rep[1] = 0;
		while (rep[1] < goal->sp_count)
		{
			if ((int)goal->sp_data[rep[1]].dist
				== (int)other->sp_data[rep[0] - (goal->sp_count + 1)].dist)
			{
				rep[1] = -1;
				break ;
			}
			rep[1]++;
		}
		if (rep[1] != -1 && other->sp_data[rep[0]
				- (goal->sp_count + 1)].dist < dist)
			newdata[rep[0] - 1] = other->sp_data[rep[0] - (goal->sp_count + 1)];
		rep[0]++;
	}
	return (rep[0] - 1);
}
