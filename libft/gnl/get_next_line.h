/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:07:21 by jsiller           #+#    #+#             */
/*   Updated: 2021/10/03 19:58:40 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define OPEN_MAX 1024

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft.h"
# define BUFFER_SIZE 100

int		get_next_line(int fd, char **line);
int		ft_nl(char *buf);

#endif