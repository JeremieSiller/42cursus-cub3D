/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:57:22 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/03 20:24:19 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../cub.h"
# include "../sprite/sprite.h"

# define FONT_WIDTH 10
# define FONT_HEIGHT 20

typedef struct s_spritedata
{
	float		dist;
	float		x;
	float		y;
	t_sprite	*sprite;
}				t_spritedata;

/*
** Struct that has data about what quadrent was hit
** x, y are the positions we checked
** dist is the 2D distance to the wall
** img: - 1. NORTH
**		- 2. EAST
**		- 3. SOUTH
**		- 4. WEST
*/
typedef struct s_data
{
	float			dist;
	t_line			*ray;
	float			x;
	float			y;
	int				img;
	int				sp_count;
	t_spritedata	*sp_data;
}				t_data;

int				ft_spritecheck(t_data *data, t_mlx *mlx,
					int x_y[2], t_data *ret);
void			ft_setdata(float deg, t_line *ray,
					t_mlx *mlx, t_data *data);
int				ft_setnewdata(t_spritedata *newdata,
					t_data *goal, t_data *other, float dist);
/*
** Color Functions
*/

unsigned int	ft_argb2uint(int a, int r, int g, int b);
unsigned int	ft_tcolour2uint(t_colour color);
t_colour		ft_uint2tcolour(unsigned int color);

/*
** Game Render Functions
*/

void			ft_rendergame(t_mlx *mlx);
t_data			ft_eastvertical(t_line *ray, t_mlx *mlx);
t_data			ft_westvertical(t_line *ray, t_mlx *mlx);
t_data			ft_northhorizontal(t_line *ray, t_mlx *mlx);
t_data			ft_southhorizontal(t_line *ray, t_mlx *mlx);

/*
** Menu Render Functions
*/

int				ft_mainscreen(t_mlx *mlx);

/*
** Math Funcitons
*/

float			ft_deg2rad(float deg);
float			ft_rad2deg(float rad);
float			ft_dist(float x1, float y1, float x2, float y2);
float			ft_length(float x, float y);
float			ft_fix(float deg);

/*
** Draw Functions
*/

void			ft_putpixelimg(t_img *img, int x, int y, unsigned int color);
unsigned int	ft_getpixelimg(t_img *img, int x, int y);
void			ft_drawvertline(t_mlx *mlx, int x, t_data data, int direction);
void			ft_drawspritevert(t_mlx *mlx, t_data data, int x);
void			ft_drawline(t_img *img, t_data p1,
					t_data p2, unsigned int color);
#endif