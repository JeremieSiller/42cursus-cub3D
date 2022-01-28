/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:08:06 by jsiller           #+#    #+#             */
/*   Updated: 2021/06/26 17:48:06 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void static	ft_revers(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int static	ft_ternary(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		s_n;

	str = malloc(13);
	if (!str)
		return (0);
	i = 0;
	s_n = n;
	if (n == 0)
		str[i] = '0';
	while (n)
	{
		str[i] = ft_ternary(n % 10) + '0';
		n /= 10;
		i++;
	}
	if (s_n < 0)
		str[i] = '-';
	if (s_n < 0 || s_n == 0)
		i++;
	str[i] = '\0';
	ft_revers(str);
	return (str);
}
