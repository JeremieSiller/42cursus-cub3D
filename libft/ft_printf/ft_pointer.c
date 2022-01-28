/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:42:38 by jsiller           #+#    #+#             */
/*   Updated: 2021/07/01 15:58:51 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_revers(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen_b(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

char	*ft_hex_buf(unsigned long long nbr, int big)
{
	char	*buf;
	int		i;

	buf = malloc(32);
	if (!buf)
		return (0);
	i = 0;
	if (nbr == 0)
		buf[i++] = '0';
	while (nbr)
	{
		if (nbr % 16 < 10)
			buf[i] = nbr % 16 + '0';
		else if (big)
			buf[i] = (nbr % 16) - 10 + 'A';
		else
			buf[i] = (nbr % 16) - 10 + 'a';
		i++;
		nbr /= 16;
	}
	buf[i] = 0;
	ft_revers(buf);
	return (buf);
}

static void	ft_left(char *str)
{
	int	i;

	i = 0;
	ft_putstr_a("0x", 2);
	while (str[i])
		ft_putchar_a(str[i++]);
	while (i < g_width - 2)
	{
		ft_putchar_a(' ');
		i++;
	}
}

static void	ft_none(char *str)
{
	int	i;

	i = 0;
	while (i < g_width - ft_strlen_b(str) - 2)
	{
		ft_putchar_a(' ');
		i++;
	}
	i = 0;
	ft_putstr_a("0x", 2);
	while (str[i])
		ft_putchar_a(str[i++]);
}

int	ft_pointer(void)
{
	char	*str;

	str = ft_hex_buf(va_arg(g_args, unsigned long long), FALSE);
	if (!str)
		return (-1);
	if (str[0] == '0' && str[1] == 0 && g_precision == 0)
		str[0] = 0;
	if (g_sign == LEFT)
		ft_left(str);
	if (g_sign == NONE)
		ft_none(str);
	free(str);
	return (0);
}
