/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_infoblock_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:42:10 by jsiller           #+#    #+#             */
/*   Updated: 2021/09/17 15:20:11 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "validate.h"

int	got_all_info(t_file *file)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (file->txt[i].path == 0)
			return (0);
		i++;
	}
	if (file->clr[0].b == -1 || file->clr[1].b == -1)
		return (0);
	return (1);
}

int	info_parser(t_file *file, char **tmp, int i)
{
	if (!tmp)
	{
		ft_putstr_fd("Error:\ncould not allocate memory\n", 2);
		free_texture(file);
		free_line(file->line);
		return (1);
	}
	if (parse_info(file, tmp, i))
	{
		free_line(tmp);
		free_texture(file);
		free_line(file->line);
		return (1);
	}
	return (0);
}
