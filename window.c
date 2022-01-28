/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:06:01 by nschumac          #+#    #+#             */
/*   Updated: 2021/09/26 18:27:15 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	ft_create_window(t_mlx *mlx, int width, int height, char *title)
{
	mlx->win.win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, title);
	if (!mlx->win.win_ptr)
		return (0);
	mlx->win.width = width;
	mlx->win.height = height;
	return (1);
}
