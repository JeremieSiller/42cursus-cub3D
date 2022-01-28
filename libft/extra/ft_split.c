/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:09:38 by jsiller           #+#    #+#             */
/*   Updated: 2021/09/17 14:25:01 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_protected(char *str, int (arr)[3])
{
	char	**ret;

	if (!str)
		return (0);
	if (str && str[0] == 0)
	{
		ret = malloc(sizeof(*ret));
		(ret)[0] = NULL;
		return (ret);
	}
	ret = malloc(sizeof(char *) * ft_strlen(str) + 1);
	if (!ret)
		return (0);
	arr[0] = 0;
	arr[1] = 0;
	return (ret);
}

char	**ft_split(char *str, char c)
{
	char	**ret;
	int		arr[3];

	ret = ft_protected(str, arr);
	if (!ret || str[0] == 0)
		return (ret);
	while (str[arr[0]])
	{
		while (str[arr[0]] == c && str[arr[0]])
			arr[0]++;
		if (str[arr[0]])
		{
			arr[2] = arr[0];
			while (str[arr[0]] != c && str[arr[0]])
				arr[0]++;
			ret[arr[1]] = malloc(arr[0] - arr[2] + 1);
			ft_memcpy(ret[arr[1]], &(str[arr[2]]), arr[0] - arr[2]);
			ret[arr[1]][arr[0] - arr[2]] = 0;
			arr[1]++;
		}
		if (str[arr[0]])
			arr[0]++;
	}
	ret[arr[1]] = 0;
	return (ret);
}
