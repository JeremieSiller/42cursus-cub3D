/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:16:22 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/03 19:02:55 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

unsigned int	ft_argb2uint(int a, int r, int g, int b)
{
	unsigned int	ret;

	ret = 0;
	a = 255 - a;
	ret += a << 24;
	ret += r << 16;
	ret += g << 8;
	ret += b;
	return (ret);
}

unsigned int	ft_tcolour2uint(t_colour color)
{
	unsigned int	ret;

	ret = 0;
	color.a = 255 - color.a;
	ret += color.a << 24;
	ret += color.r << 16;
	ret += color.g << 8;
	ret += color.b;
	return (ret);
}

t_colour	ft_uint2tcolour(unsigned int color)
{
	t_colour	ret;

	ret.a = 255 - (color >> 24) & 0xFF;
	ret.r = (color >> 16) & 0xFF;
	ret.g = (color >> 8) & 0xFF;
	ret.b = color & 0xFF;
	return (ret);
}
