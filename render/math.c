/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:53:48 by nschumac          #+#    #+#             */
/*   Updated: 2021/09/21 18:37:48 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*
** Converts angle in grad to angle in rad
*/
float	ft_deg2rad(float deg)
{
	return (deg / 360.f * 2 * M_PI);
}

/*
** Converts angle in radians to angle in grad
*/
float	ft_rad2deg(float rad)
{
	return (rad / (2 * M_PI) * 360.f);
}

/*
** Calculates the distance between two points
** in a two dimensional room
*/
float	ft_dist(float x1, float y1, float x2, float y2)
{
	return (sqrtf(powf(x1 - x2, 2.f) + powf(y1 - y2, 2.f)));
}

/*
** Calculates the length of a vector
*/
float	ft_length(float x, float y)
{
	return (sqrtf(powf(x, 2.f) + powf(y, 2.f)));
}

/*
** Fixes the degrees, so they are inbetween 0 and 360
*/
float	ft_fix(float deg)
{
	while (deg > 360.f)
		deg -= 360.f;
	while (deg < 0.f)
		deg += 360.f;
	return (deg);
}
