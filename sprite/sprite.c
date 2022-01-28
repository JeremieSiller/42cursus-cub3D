/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:26:00 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/03 18:51:19 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "../render/render.h"

/*
** Creates a new sprite type
** it is malloced
*/
t_sprite	*ft_createsprite(void *mlx,
		char *path, int frame_size, int frame_count)
{
	t_sprite	*ret;

	ret = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!ret)
		return (NULL);
	ret->spritesheet = ft_new_xpm(mlx, path);
	if (!ret->spritesheet)
	{
		free(ret);
		return (NULL);
	}
	ret->frame_count = frame_count;
	ret->displayimg = ft_new_mlx_img(mlx, frame_size, frame_size);
	if (!ret->displayimg)
	{
		ft_free_allimg(NULL, mlx, ret->spritesheet);
		free(ret);
		return (NULL);
	}
	return (ret);
}

/*
** Returns the x position relative to the sprite sheet
*/
static int	ft_xpos(t_sprite *sprite)
{
	int	ret;

	ret = sprite->current_frame;
	while (ret > sprite->spritesheet->width / sprite->displayimg->width)
		ret -= sprite->spritesheet->width / sprite->displayimg->width;
	return (ret * sprite->displayimg->width);
}

/*
** Returns the y position relative to the sprite sheet
*/
static int	ft_ypos(t_sprite *sprite)
{
	int	ret;

	ret = sprite->current_frame
		/ (sprite->spritesheet->width / sprite->displayimg->width);
	return (ret * sprite->displayimg->width);
}

/*
** Overwrites all pixels of the displayimage to Current
** Sprite Frame
** Set the current sprite frame then call this function to change the appearence
*/
void	ft_setframe(t_sprite *sprite)
{
	int	x;
	int	y;

	y = 0;
	while (y < sprite->displayimg->height)
	{
		x = 0;
		while (x < sprite->displayimg->width)
		{
			ft_putpixelimg(sprite->displayimg, x, y,
				ft_getpixelimg(sprite->spritesheet,
					ft_xpos(sprite) + x, ft_ypos(sprite) + y));
			x++;
		}
		y++;
	}
}

int	ft_setsprites(t_mlx *mlx)
{
	mlx->sprites = (t_sprite **)ft_calloc(2, sizeof(t_sprite *));
	if (!mlx->sprites)
		return (0);
	mlx->sprites[SP_COIN] = ft_createsprite(mlx->mlx_ptr,
			"./resources/coin.xpm", 84, 6);
	if (!mlx->sprites[SP_COIN])
	{
		free(mlx->sprites);
		return (0);
	}
	mlx->sprites[SP_DOOR] = ft_createsprite(mlx->mlx_ptr,
			"./resources/coin.xpm", 84, 6);
	if (!mlx->sprites[SP_DOOR])
	{
		ft_free_allimg(mlx, NULL, mlx->sprites[SP_COIN]->spritesheet);
		ft_free_allimg(mlx, NULL, mlx->sprites[SP_COIN]->displayimg);
		free(mlx->sprites);
		return (0);
	}
	return (1);
}
