/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:21:57 by jsiller           #+#    #+#             */
/*   Updated: 2021/10/03 18:44:09 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "validate.h"

static void	get_width(char **line, int i, t_map *map)
{
	map->x = 0;
	while (line[i])
	{
		if ((int)ft_strlen(line[i]) > map->x)
			map->x = (int)ft_strlen(line[i]);
		i++;
	}
}

static int	check_file(t_file *file, int i)
{
	int	j;

	while (file->line[i])
	{
		j = 0;
		while (file->line[i][j])
		{
			if (!ft_strchr(ALLOWED, file->line[i][j]))
			{
				ft_putstr_fd("Error\nmap contains unallowed chars\n", 2);
				free_line(file->line);
				free_texture(file);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static char	**fill_map(t_file *file, char **ret, int d)
{
	int	i;
	int	j;

	i = 0;
	while (ret && i < file->map.x)
	{
		j = 0;
		while (j < file->map.y)
		{
			if (!file->line[j + d][0])
			{
				ft_putstr_fd("Error:\nfound empty line in map\n", 2);
				free_line(ret);
				free_texture(file);
				free_line(file->line);
				exit(1);
			}
			if (i < (int)ft_strlen(file->line[j + d]))
				(ret[i])[j] = file->line[j + d][i];
			j++;
		}
		i++;
	}
	return (ret);
}

static char	**create_map(t_file *file, int i)
{
	char	**ret;
	int		j;
	int		d;

	ret = ft_calloc(file->map.x + 1, sizeof(char **));
	j = 0;
	d = i;
	while (ret && j < file->map.x)
	{
		ret[j] = ft_calloc((file->map.y + 1), 1);
		if (!ret[j])
		{
			free_line(ret);
			return (0);
		}
		ft_memset(ret[j], ' ', file->map.y);
		i++;
		j++;
	}
	return (fill_map(file, ret, d));
}

int	map_handler(t_file *file, int i)
{
	while (file->line[i] && !file->line[i][0])
		i++;
	if (!file->line[i])
	{
		ft_putstr_fd("Error:\nno map in file\n", 2);
		free_line(file->line);
		free_texture(file);
		return (1);
	}
	if (check_file(file, i))
		return (1);
	file->map.y = get_height(file->line + i);
	get_width(file->line, i, &file->map);
	file->map.arr = create_map(file, i);
	free_line(file->line);
	if (!file->map.arr)
	{
		free_texture(file);
		ft_putstr_fd("Error:\ncould not allocate memory\n", 2);
		return (1);
	}
	return (0);
}
