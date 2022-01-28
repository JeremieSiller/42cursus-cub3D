/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:47:49 by jsiller           #+#    #+#             */
/*   Updated: 2021/06/18 17:14:04 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_char(void)
{
	char	c;
	int		i;

	c = va_arg(g_args, int);
	i = 0;
	if (g_sign == LEFT)
		ft_putchar_a(c);
	while (i < g_width - 1)
	{
		ft_putchar_a(32);
		i++;
	}
	if (g_sign == NONE)
		 ft_putchar_a(c);
	return (0);
}
