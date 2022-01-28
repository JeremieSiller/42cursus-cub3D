/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percentage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:18:51 by jsiller           #+#    #+#             */
/*   Updated: 2021/06/18 17:14:32 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_percentage(void)
{
	char	c;
	int		i;

	c = '%';
	i = 0;
	if (g_sign == LEFT)
		ft_putchar_a(c);
	while (i < g_width - 1)
	{
		if (g_padding && g_sign == NONE)
			ft_putchar_a('0');
		else
			ft_putchar_a(32);
		i++;
	}
	if (g_sign == NONE)
		 ft_putchar_a(c);
	return (0);
}
