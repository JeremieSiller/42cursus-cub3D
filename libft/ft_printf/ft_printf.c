/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:15:58 by jsiller           #+#    #+#             */
/*   Updated: 2021/06/23 19:20:17 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_init_flags(void)
{
	g_width = 0;
	g_padding = FALSE;
	g_precision = -1;
	g_sign = NONE;
}

int	ft_printf(const char *format, ...)
{
	int	i;

	i = 0;
	if (!format)
		return (-1);
	g_ret = 0;
	va_start(g_args, format);
	ft_init_flags();
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_a(format[i]);
		if (format[i] == '%' && ft_arguement((char *)format, &i) == -1)
		{
			va_end(g_args);
			return (-1);
		}
		ft_init_flags();
		i++;
	}
	va_end(g_args);
	return (g_ret);
}
