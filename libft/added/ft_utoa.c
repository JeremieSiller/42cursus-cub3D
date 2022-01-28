/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:42:14 by jsiller           #+#    #+#             */
/*   Updated: 2021/07/01 15:58:11 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_revers(char *str)
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

char	*ft_utoa(unsigned int n)
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
	if (s_n == 0)
		i++;
	str[i] = '\0';
	ft_revers(str);
	return (str);
}
