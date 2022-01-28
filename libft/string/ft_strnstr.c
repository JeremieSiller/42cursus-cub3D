/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:51:44 by jsiller           #+#    #+#             */
/*   Updated: 2021/06/26 17:51:40 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	char	*ret;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		k = 0;
		ret = (char *)&(haystack[i]);
		while (haystack[k + i] && needle[k] && haystack[k + i] == needle[k]
			&& k + i < len)
			k++;
		if (needle[k] == '\0')
			return (ret);
		i++;
	}
	return (NULL);
}
