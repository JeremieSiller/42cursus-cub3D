/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_legit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:02:40 by jsiller           #+#    #+#             */
/*   Updated: 2021/10/03 18:50:21 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "../cub.h"

static int	check_borders(t_map *map)
{
	int	x;
	int	y;
	int	ret;

	x = 0;
	y = 0;
	ret = 0;
	while (x < map->x)
	{
		if ((map->arr[x][0] != ' ' && map->arr[x][0] != '1') || (map->
			arr[x][map->y - 1] != ' ' && map->arr[x][map->y - 1] != '1'))
			ret = 1;
		x++;
	}
	while (y < map->y)
	{
		if ((map->arr[0][y] != ' ' && map->arr[0][y] != '1') || (map->
			arr[map->x - 1][y] != ' ' && map->arr[map->x - 1][y] != '1'))
			ret = 1;
		y++;
	}
	if (ret)
		ft_putstr_fd("Error\nmap not sorrounded\n", 2);
	return (ret);
}

static int	check_player_pos(t_map *map, int x, int y)
{
	if (x == 0 || y == 0 || x + 1 == map->x || y + 1 == map->y)
		return (1);
	if (x > 0 && y > 0 && map->arr[x - 1][y - 1] == ' ')
		return (1);
	if (x > 0 && map->arr[x - 1][y] == ' ')
		return (1);
	if (y > 0 && map->arr[x][y - 1] == ' ')
		return (1);
	if (x > 0 && y + 1 < map->y && map->arr[x - 1][y + 1] == ' ')
		return (1);
	if (x + 1 < map->x && map->arr[x + 1][y] == ' ')
		return (1);
	if (y + 1 < map->y && map->arr[x][y + 1] == ' ')
		return (1);
	if (y + 1 < map->y && x + 1 < map->x && map->arr[x + 1][y + 1] == ' ')
		return (1);
	if (x + 1 < map->x && y > 0 && map->arr[x + 1][y - 1] == ' ')
		return (1);
	return (0);
}

static int	fill_player(t_map *map, int x, int y, t_player *player)
{
	if (player->view_direction != -1)
	{
		ft_putstr_fd("Error\nFound more than one player position\n", 2);
		return (1);
	}
	if (check_player_pos(map, x, y))
	{
		ft_putstr_fd("Error\nPlayer not in map\n", 2);
		return (1);
	}
	if (map->arr[x][y] == 'N')
		player->view_direction = 90.0f;
	if (map->arr[x][y] == 'W')
		player->view_direction = 180.0f;
	if (map->arr[x][y] == 'S')
		player->view_direction = 270.0f;
	if (map->arr[x][y] == 'E')
		player->view_direction = 0.0f;
	player->x_coord = (float)x;
	player->y_coord = (float)y;
	player->fov = 60.0f;
	return (0);
}

static int	check_sorrounding(t_map *map, int x, int y)
{
	if (x > 0 && y > 0 && map->arr[x - 1][y - 1] != ' ' &&
		map->arr[x - 1][y - 1] != '1')
		return (1);
	if (x > 0 && map->arr[x - 1][y] != ' ' && map->arr[x - 1][y] != '1')
		return (1);
	if (y > 0 && map->arr[x][y - 1] != ' ' && map->arr[x][y - 1] != '1')
		return (1);
	if (x > 0 && y + 1 < map->y && map->arr[x - 1][y + 1] != ' ' &&
		map->arr[x - 1][y + 1] != '1')
		return (1);
	if (x + 1 < map->x && map->arr[x + 1][y] != ' ' &&
		map->arr[x + 1][y] != '1')
		return (1);
	if (y + 1 < map->y && map->arr[x][y + 1] != ' ' &&
		map->arr[x][y + 1] != '1')
		return (1);
	if (y + 1 < map->y && x + 1 < map->x && map->arr[x + 1][y + 1] != '1' &&
		map->arr[x + 1][y + 1] != ' ')
		return (1);
	if (x + 1 < map->x && y > 0 && map->arr[x + 1][y - 1] != '1' &&
		map->arr[x + 1][y - 1] != ' ')
		return (1);
	return (0);
}

int	is_map_valid(t_map *map, t_player *player)
{
	int		ix;
	int		iy;

	ix = 0;
	player->view_direction = -1.0f;
	while (ix < map->x)
	{
		iy = 0;
		while (iy < map->y)
		{
			if ((map->arr[ix][iy] == 'W' || map->arr[ix][iy] == 'N'
				|| map->arr[ix][iy] == 'E' || map->arr[ix][iy] == 'S') &&
				fill_player(map, ix, iy, player))
				return (1);
			if (map->arr[ix][iy] == ' ' && check_sorrounding(map, ix, iy))
			{
				ft_putstr_fd("Error\nmap not sorrounded\n", 2);
				return (1);
			}
			iy++;
		}
		ix++;
	}
	return (check_borders(map));
}
