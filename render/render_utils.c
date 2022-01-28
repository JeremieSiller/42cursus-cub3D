/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:42:24 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/03 19:42:48 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	ft_checkfield(t_data *data, t_mlx *mlx, int x, int y)
{
	t_spritedata	*newdata;
	int				count;
	t_data			ret;

	if (mlx->file.map.arr[x][y] == '1')
		return (1);
	else if (ft_strchr(SPRITES, mlx->file.map.arr[x][y]))
	{
		if (!ft_spritecheck(data, mlx, (int [2]){x, y}, &ret))
			return (0);
		newdata = malloc(++data->sp_count * sizeof(t_spritedata));
		if (!newdata)
			return (0);
		count = 0;
		while (++count < data->sp_count)
			newdata[count - 1] = data->sp_data[count - 1];
		newdata[count - 1].dist = ret.dist;
		newdata[count - 1].x = ret.x;
		newdata[count - 1].y = ret.y;
		newdata[count - 1].sprite = mlx->sprites[SP_COIN];
		if (data->sp_data)
			free(data->sp_data);
		data->sp_data = newdata;
	}
	return (0);
}

/*
** this function looks east and
** only at the vertical lines
** it returns the intersection of the ray with a box
*/
t_data	ft_eastvertical(t_line *ray, t_mlx *mlx)
{
	t_data	ret;

	ret.dist = 340282346638528859811704183484516925440.f;
	ret.img = 2;
	ret.sp_count = 0;
	ret.sp_data = NULL;
	ret.ray = ray;
	ret.x = (int)mlx->player.x_coord + (mlx->cube_size
			- ((int)mlx->player.x_coord % mlx->cube_size));
	while ((int)ret.x < mlx->cube_size * mlx->file.map.x)
	{
		ret.y = ray->m * ret.x + ray->t;
		if (ret.y < 0 && ret.y > -mlx->cube_size * (mlx->file.map.y - 1))
		{
			if (ft_checkfield(&ret, mlx, (int)ret.x / mlx->cube_size,
					abs((int)(ret.y / mlx->cube_size))))
			{
				ret.dist = ft_dist(ret.x, ret.y,
						mlx->player.x_coord, mlx->player.y_coord);
				return (ret);
			}
		}
		ret.x += mlx->cube_size;
	}
	return (ret);
}

/*
** this function looks west and
** only at the vertical lines
** it returns the intersection of the ray with a box
*/
t_data	ft_westvertical(t_line *ray, t_mlx *mlx)
{
	t_data	ret;

	ret.dist = 340282346638528859811704183484516925440.f;
	ret.img = 4;
	ret.sp_count = 0;
	ret.sp_data = NULL;
	ret.x = (int)mlx->player.x_coord
		- ((int)mlx->player.x_coord % mlx->cube_size);
	ret.ray = ray;
	while (ret.x > 0)
	{
		ret.y = ray->m * ret.x + ray->t;
		if (ret.y < 0 && ret.y > -mlx->cube_size * (mlx->file.map.y - 1))
		{
			if (ft_checkfield(&ret, mlx, ((int)ret.x / mlx->cube_size) - 1,
					abs((int)(ret.y / mlx->cube_size))))
			{
				ret.dist = ft_dist(ret.x, ret.y,
						mlx->player.x_coord, mlx->player.y_coord);
				return (ret);
			}
		}
		ret.x -= mlx->cube_size;
	}
	return (ret);
}

/*
** this function looks north and
** only at the horizontal lines
** it returns the intersection of the ray with a box
*/
t_data	ft_northhorizontal(t_line *ray, t_mlx *mlx)
{
	t_data	ret;

	ret.dist = 340282346638528859811704183484516925440.f;
	ret.img = 1;
	ret.sp_count = 0;
	ret.sp_data = NULL;
	ret.y = (int)mlx->player.y_coord
		+ (abs((int)mlx->player.y_coord % mlx->cube_size));
	ret.ray = ray;
	while (ret.y < 0)
	{
		ret.x = (ret.y - ray->t) / ray->m;
		if (ret.x > 0 && ret.x < (mlx->cube_size - 1) * mlx->file.map.x)
		{
			if (ft_checkfield(&ret, mlx, (int)ret.x / mlx->cube_size,
					abs((int)ret.y / mlx->cube_size) - 1))
			{
				ret.dist = ft_dist(ret.x, ret.y,
						mlx->player.x_coord, mlx->player.y_coord);
				return (ret);
			}
		}
		ret.y += mlx->cube_size;
	}
	return (ret);
}

/*
** this function looks south and
** only at the horizontal lines
** it returns the intersection of the ray with a box
*/
t_data	ft_southhorizontal(t_line *ray, t_mlx *mlx)
{
	t_data	ret;

	ret.dist = 340282346638528859811704183484516925440.f;
	ret.img = 3;
	ret.sp_count = 0;
	ret.sp_data = NULL;
	ret.y = (int)mlx->player.y_coord - (mlx->cube_size
			- abs((int)mlx->player.y_coord % mlx->cube_size));
	ret.ray = ray;
	while (ret.y > -mlx->cube_size * mlx->file.map.y)
	{
		ret.x = (ret.y - ray->t) / ray->m;
		if (ret.x > 0 && ret.x < (mlx->cube_size - 1) * mlx->file.map.x)
		{
			if (ft_checkfield(&ret, mlx, (int)ret.x / mlx->cube_size,
					abs((int)ret.y / mlx->cube_size)))
			{
				ret.dist = ft_dist(ret.x, ret.y,
						mlx->player.x_coord, mlx->player.y_coord);
				return (ret);
			}
		}
		ret.y -= mlx->cube_size;
	}
	return (ret);
}
