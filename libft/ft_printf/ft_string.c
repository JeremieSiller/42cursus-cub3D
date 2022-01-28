/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:25:25 by jsiller           #+#    #+#             */
/*   Updated: 2021/07/01 15:54:35 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_left_string(char *str)
{
	int	i;

	i = 0;
	while (i < g_precision)
	{
		ft_putchar_a(str[i]);
		i++;
	}
	while (i < g_width)
	{
		ft_putchar_a(32);
		i++;
	}
	return (0);
}

static int	ft_none_string(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g_width - g_precision)
	{
		ft_putchar_a(32);
		i++;
	}
	while (i < g_width || i < g_precision)
	{
		ft_putchar_a(str[j]);
		i++;
		j++;
	}
	return (0);
}

int	ft_string(void)
{
	char	*str;
	int		i;
	int		null;

	str = va_arg(g_args, char *);
	i = 0;
	null = FALSE;
	if (!str)
	{
		str = ft_strdup("(null)");
		null = TRUE;
	}
	if (!str)
		return (-1);
	if (g_width == 0 && g_precision <= -1)
		g_width = ft_strlen_b(str);
	if (g_precision <= -1 || g_precision >= ft_strlen_b(str))
		g_precision = ft_strlen_b(str);
	if (g_sign == LEFT)
		ft_left_string(str);
	if (g_sign == NONE)
		ft_none_string(str);
	if (null)
		free(str);
	return (0);
}
