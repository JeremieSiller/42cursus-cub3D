/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:54:58 by jsiller           #+#    #+#             */
/*   Updated: 2021/07/01 15:57:43 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_left_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
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
	while (i < g_width - ft_strlen_b(str))
	{
		if (g_padding && g_precision < 0)
			ft_putchar_a('0');
		else
			ft_putchar_a(32);
		i++;
	}
	while (str[j])
	{
		ft_putchar_a(str[j]);
		i++;
		j++;
	}
	return (0);
}

static char	*ft_precise_b(char *str, char *ret, int i, int k)
{
	int	j;

	j = 0;
	if (str[i] == '-')
	{
		ret[i] = '-';
		str++;
		i++;
	}
	while (k < g_precision - ft_strlen_b(str))
	{
		ret[i] = '0';
		i++;
		k++;
	}
	j = 0;
	while (str[j])
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[i] = 0;
	return (ret);
}

static char	*ft_precise(char *str)
{
	char	*ret;

	if (g_precision < ft_strlen_b(str))
		ret = malloc(ft_strlen_b(str) + g_width + 1);
	else
		ret = malloc(g_precision + 1);
	if (!ret)
		return (0);
	if (g_padding && g_width > ft_strlen_b(str) && g_precision == -1)
	{
		g_precision = g_width;
		if (str[0] == '-')
			g_precision--;
	}
	if (ft_strlen_b(str) == 1 && str[0] == '0' && g_precision == 0)
	{
		ret[0] = 0;
		return (ret);
	}
	if (g_precision <= ft_strlen_b(str))
	{
		ft_strcpy(ret, str);
		return (ret);
	}
	return (ft_precise_b(str, ret, 0, 0));
}

int	ft_unsigned(void)
{
	char	*str;
	char	*s2;

	str = ft_utoa(va_arg(g_args, unsigned int));
	if (!str)
		return (-1);
	if (g_precision < -1)
		g_precision = -1;
	s2 = ft_precise(str);
	free(str);
	if (!s2)
		return (-1);
	if (g_sign == LEFT)
		ft_left_string(s2);
	if (g_sign == NONE)
		ft_none_string(s2);
	free(s2);
	return (0);
}
