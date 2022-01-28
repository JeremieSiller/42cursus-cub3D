/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 09:53:03 by jsiller           #+#    #+#             */
/*   Updated: 2021/07/01 17:12:00 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_a(char c)
{
	write(1, &c, 1);
	g_ret++;
}

int	ft_strlen_b(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_a(char *str, int len)
{
	while (*str && len--)
	{
		write(1, str++, 1);
		g_ret++;
	}
}
