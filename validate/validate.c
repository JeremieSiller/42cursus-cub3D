/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:32:38 by jsiller           #+#    #+#             */
/*   Updated: 2021/09/18 18:21:16 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "validate.h"

static int	readfile(t_file *file)
{
	int		i;
	int		ret;
	char	*tmp;

	file->line = ft_calloc(2, sizeof(*(file->line)));
	if (!file->line)
		return (1);
	ret = get_next_line(file->fd, &file->line[0]);
	i = 1;
	while (ret == 1)
	{
		ret = get_next_line(file->fd, &tmp);
		if (ret == -1)
			break ;
		if (append_line(file, tmp, i))
			return (1);
		i++;
	}
	if (ret == -1)
	{
		free_line(file->line);
		ft_putstr_fd("Error:\ncould not allocate memory\n", 2);
		return (1);
	}
	return (0);
}

static int	validate_info(t_file *file, int	i)
{
	if (!got_all_info(file))
		ft_putstr_fd("Error\ninfo block not complete", 2);
	if (file->line[i][0])
		ft_putstr_fd("Error:\nno empty line after info block\n", 2);
	if (!got_all_info(file) || file->line[i][0])
	{
		free_line(file->line);
		free_texture(file);
		return (1);
	}
	return (0);
}

static int	get_info(t_file *file)
{
	int		i;
	char	**tmp;

	i = 0;
	while (!got_all_info(file) && file->line[i])
	{
		if (file->line[i][0] == 0)
		{
			i++;
			continue ;
		}
		tmp = ft_split(file->line[i], ' ');
		if (info_parser(file, tmp, i))
			return (1);
		free_line(tmp);
		i++;
	}
	if (validate_info(file, i))
		return (1);
	return (map_handler(file, i + 1));
}

static int	check_map_valid_return(t_file *file)
{
	if (is_map_valid(&file->map, &file->player))
	{
		free_texture(file);
		free_line(file->map.arr);
		return (1);
	}
	if (file->player.view_direction < 0)
	{
		ft_putstr_fd("Error:\nno player found\n", 2);
		free_texture(file);
		free_line(file->map.arr);
		return (1);
	}
	return (0);
}

int	valdiate(char *str, t_file *file)
{
	file->fd = open(str, O_RDONLY);
	if (file->fd < 0)
	{
		ft_putstr_fd("Error:\n", 2);
		perror(str);
		return (1);
	}
	if (check_name(str) == 1)
		return (1);
	if (readfile(file))
		return (1);
	close(file->fd);
	if (get_info(file))
		return (1);
	return (check_map_valid_return(file));
}
