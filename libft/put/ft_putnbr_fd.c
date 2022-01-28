/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 23:57:14 by jsiller           #+#    #+#             */
/*   Updated: 2021/06/26 17:51:02 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	temp;
	int		arr[20];
	int		i;

	i = 0;
	if (n < 0)
		write(fd, "-", 1);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	while (n != 0)
	{
		arr[i] = n % 10;
		if (arr[i] < 0)
			arr[i] *= -1;
		i++;
		n /= 10;
	}
	while (i--)
	{
		temp = arr[i] + '0';
		write(fd, &temp, 1);
	}
}
