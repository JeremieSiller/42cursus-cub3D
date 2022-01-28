/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:12:05 by jsiller           #+#    #+#             */
/*   Updated: 2021/07/01 17:12:33 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

# define FALSE 0
# define TRUE 1
# define NONE 0
# define LEFT 1

# define FLAGS "-0"
# define WIDTH "*0123456789"
# define TYPES "cspdiuxX%n"

int		g_ret;
int		g_width;
int		g_precision;
int		g_padding;
int		g_sign;
va_list	g_args;

int		ft_printf(const char *input, ...);

void	ft_putchar_a(char c);
void	ft_putstr_a(char *str, int len);
int		ft_arguement(char *input, int *i);

int		ft_char(void);
int		ft_string(void);
char	*ft_strdup(const char *src);
int		ft_integer(int big);
int		ft_pointer(void);
int		ft_percentage(void);
int		ft_unsigned(void);
int		ft_store(void);
int		ft_strlen_b(char *str);
char	*ft_hex_buf(unsigned long long nbr, int big);

#endif