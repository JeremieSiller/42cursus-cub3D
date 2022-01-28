/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:07:20 by jsiller           #+#    #+#             */
/*   Updated: 2021/10/02 16:18:13 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H
# include <fcntl.h>
# define ALLOWED "01NSEWC "
# include "../cub.h"
/*
** file: validate_utils.c
*/
int		get_height(char **s);
int		check_name(char *str);
void	free_line(char **line);
int		append_line(t_file *file, char *line, int i);
void	free_texture(t_file *file);

/*
** file: validate_infoblock.c
*/
int		parse_info(t_file *file, char **tmp, int i);

/*
** file: validate_infoblock_utils.c
*/
int		got_all_info(t_file *file);
int		info_parser(t_file *file, char **tmp, int i);

/*
** file: map_handler.c
*/
int		map_handler(t_file *file, int i);

/*
** file: map_legit.c
*/
int		is_map_valid(t_map *map, t_player *player);
#endif
