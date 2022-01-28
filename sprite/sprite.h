/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:00:30 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/03 18:49:54 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "../cub.h"

/*
** Sprites position in sprite array
*/
# define SP_COIN 0
# define SP_DOOR 1

/*
** SPRITE STRING:
**				C = COIN
**				D = DOOR
*/
# define SPRITES "CD"

t_sprite	*ft_createsprite(void *mlx,
				char *path, int frame_size, int frame_count);

void		ft_setframe(t_sprite *sprite);

int			ft_setsprites(t_mlx *mlx);

#endif