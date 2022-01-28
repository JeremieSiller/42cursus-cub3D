/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infoblock.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:45:54 by jsiller           #+#    #+#             */
/*   Updated: 2021/09/27 13:24:03 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "validate.h"

static int	parse_texture(t_file *file, char **tmp)
{
	char	*str;

	str = ft_strdup(tmp[1]);
	if (!str)
	{
		ft_putstr_fd("Error:\nCould not allocate memory\n", 2);
		return (1);
	}
	if (!ft_strncmp(tmp[0], "NO", 3))
		file->txt[NORTH].path = str;
	else if (!ft_strncmp(tmp[0], "EA", 3))
		file->txt[EAST].path = str;
	else if (!ft_strncmp(tmp[0], "SO", 3))
		file->txt[SOUTH].path = str;
	else if (!ft_strncmp(tmp[0], "WE", 3))
		file->txt[WEST].path = str;
	return (0);
}

static int	only_has_digits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

static int	valid_numbers(char **clrs, t_file *file, int c)
{
	int	i;

	i = 0;
	while (clrs[i])
	{
		if (ft_strlen(clrs[i]) > 3 || only_has_digits(clrs[i]))
		{
			ft_putstr_fd("Error\nRGB number invalid\n", 2);
			free_line(clrs);
			return (1);
		}
		i++;
	}
	file->clr[c].a = 255;
	file->clr[c].r = ft_atoi(clrs[0]);
	file->clr[c].g = ft_atoi(clrs[1]);
	file->clr[c].b = ft_atoi(clrs[2]);
	if (file->clr[c].r > 255 || file->clr[c].g > 255 || file->clr[c].b > 255)
	{
		ft_putstr_fd("Error\nRGB number invalid\n", 2);
		free_line(clrs);
		return (1);
	}
	free_line(clrs);
	return (0);
}

static int	parse_colour(t_file *file, char **tmp)
{
	char	**clrs;
	int		i;

	clrs = ft_split(tmp[1], ',');
	if (!clrs)
		return (1);
	if (get_height(clrs) != 3)
	{
		free_line(clrs);
		return (1);
	}
	i = ROOF;
	if (!ft_strncmp(tmp[0], "F", 2))
		i = FLOOR;
	if (file->clr[i].r != -1)
	{
		free_line(clrs);
		ft_putstr_fd("Error:\ninfo found twice\n", 2);
		return (1);
	}
	return (valid_numbers(clrs, file, i));
}

int	parse_info(t_file *file, char **tmp, int i)
{
	if (!tmp[0] || !tmp[1] || tmp[2])
	{
		ft_putstr_fd("Error:\nInvalid line: ", 2);
		ft_putnbr_fd(i + 1, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	if (!ft_strncmp(tmp[0], "NO", 3) || !ft_strncmp(tmp[0], "SO", 3)
		|| !ft_strncmp(tmp[0], "EA", 3) || !ft_strncmp(tmp[0], "WE", 3))
		return (parse_texture(file, tmp));
	else if (!ft_strncmp(tmp[0], "F", 2) || !ft_strncmp(tmp[0], "C", 2))
		return (parse_colour(file, tmp));
	ft_putstr_fd("Error:\nInvalid line: ", 2);
	ft_putnbr_fd(i + 1, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}
