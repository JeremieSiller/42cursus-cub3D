/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:43:08 by jsiller           #+#    #+#             */
/*   Updated: 2021/09/17 15:08:03 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_height(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_name(char *str)
{
	if (ft_strncmp(".cub", str + ft_strlen(str) - 4, 5))
	{
		ft_putstr_fd("Error\n Filename does not end on \".cub\"\n", 2);
		return (1);
	}
	return (0);
}

void	free_line(char **line)
{
	int	i;

	i = get_height(line);
	while (i--)
		free(line[i]);
	free(line);
}

void	free_texture(t_file *file)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (file->txt[i].path)
			free(file->txt[i].path);
		i++;
	}
}

int	append_line(t_file *file, char *line, int i)
{
	char	**tmp;
	int		j;

	tmp = ft_calloc(sizeof(char *), i + 2);
	j = 0;
	if (!tmp)
	{
		free_line(file->line);
		free(line);
		return (1);
	}
	while (j < i)
	{
		tmp[j] = file->line[j];
		j++;
	}
	tmp[j] = line;
	free(file->line);
	file->line = tmp;
	return (0);
}
