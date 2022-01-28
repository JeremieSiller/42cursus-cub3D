/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:04:01 by jsiller           #+#    #+#             */
/*   Updated: 2021/06/24 09:27:46 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_picktype(char *input, int *i)
{
	if (g_width < 0)
	{
		g_width *= -1;
		g_sign = LEFT;
		g_padding = FALSE;
	}
	if (input[*i] == 'c' && ft_char() == -1)
		return (-1);
	if (input[*i] == 's' && ft_string() == -1)
		return (-1);
	if ((input[*i] == 'i' || input[*i] == 'd') && ft_integer(-1) == -1)
		return (-1);
	if (input[*i] == 'p' && ft_pointer() == -1)
		return (-1);
	if (input[*i] == '%' && ft_percentage() == -1)
		return (-1);
	if (input[*i] == 'x' && ft_integer(FALSE) == -1)
		return (-1);
	if (input[*i] == 'X' && ft_integer(TRUE) == -1)
		return (-1);
	if (input[*i] == 'u' && ft_unsigned() == -1)
		return (-1);
	if (input[*i] == 'n' && ft_store() == -1)
		return (-1);
	return (0);
}

int	ft_arguement_a(char *input, int *i)
{
	while (ft_strchr(WIDTH, input[*i]))
		*i += 1;
	if (input[*i] == '.')
	{
		*i += 1;
		if (input[*i] == '*')
			g_precision = va_arg(g_args, int);
		else
			g_precision = ft_atoi(&input[*i]);
		while (ft_strchr(WIDTH, input[*i]))
			*i += 1;
	}
	if (!ft_strchr(TYPES, input[*i]))
		return (-1);
	if (ft_picktype(input, i) == -1)
		return (-1);
	return (0);
}

int	ft_arguement(char *input, int *i)
{
	*i += 1;
	while (input[*i] == '0')
	{
		g_padding = TRUE;
		*i += 1;
	}
	while (input[*i] == '-')
	{
		g_sign = LEFT;
		*i += 1;
	}
	if (input[*i] == '*')
		g_width = va_arg(g_args, int);
	if (ft_strchr(WIDTH, input[*i]) && input[*i] != '*')
		g_width = ft_atoi(&input[*i]);
	return (ft_arguement_a(input, i));
}
