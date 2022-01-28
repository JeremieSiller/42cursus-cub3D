/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:18:21 by jsiller           #+#    #+#             */
/*   Updated: 2021/10/08 16:46:07 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define FLOOR 0
# define ROOF 1
# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3
# define MAIN_SCREEN 0
# define GAME_SCREEN 1
# define DONT_DO_SHIT 2

typedef enum e_keys
{
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_F,
	KEY_H,
	KEY_G,
	KEY_Z,
	KEY_X,
	KEY_C,
	KEY_V,
	KEY_B = 11,
	KEY_Q,
	KEY_W,
	KEY_E,
	KEY_R,
	KEY_Y,
	KEY_T,
	KEY_ONE,
	KEY_TWO,
	KEY_THREE,
	KEY_FOUR,
	KEY_SIX,
	KEY_FIVE,
	KEY_NINE = 25,
	KEY_SEVEN,
	KEY_EIGHT = 28,
	KEY_ZERO,
	KEY_BRACE_R,
	KEY_O,
	KEY_U,
	KEY_BRACE_L,
	KEY_I,
	KEY_P,
	KEY_L = 37,
	KEY_J,
	KEY_K = 40,
	KEY_SEMI,
	KEY_N = 45,
	KEY_M,
	KEY_TAB = 48,
	KEY_PLUS = 69,
	KEY_MINUS = 78,
	KEY_LEFT = 123,
	KEY_RIGHT,
	KEY_DOWN,
	KEY_UP,
	KEY_ESC = 0x35,
}			t_keys;

/*
**bpp = BitsPerPixel
*/
typedef struct s_imgdata
{
	int			bpp;
	int			size_line;
	int			endian;
	char		*data_addr;
}				t_imgdata;

typedef struct s_img
{
	void		*img_ptr;
	int			height;
	int			width;
	int			x;
	int			y;
	t_imgdata	data;
}				t_img;

t_img	*ft_new_mlx_img(void *mlx, int width, int height);
t_img	*ft_new_xpm(void *mlx, char *path);
t_img	*ft_resize(void	*mlx, t_img *org, float percentage);

/*
** Window Struct with all the infos
*/
typedef struct s_window
{
	void		*win_ptr;
	int			width;
	int			height;
}				t_window;

typedef struct s_line
{
	float	m;
	float	t;
}				t_line;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	float	view_direction;
	float	fov;
	float	x_coord;
	float	y_coord;
	int		move;
	float	x_move;
	float	y_move;
	int		keycode;
}				t_player;

typedef struct s_texture
{
	int		direction;
	char	*path;
	int		fd;
}				t_texture;

typedef struct s_colour
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_colour;

typedef struct s_map
{
	int		x;
	int		y;
	char	**arr;
	int		block_size;
	t_img	*org;
}	t_map;

typedef struct s_file
{
	char		**line;
	int			fd;
	t_colour	clr[2];
	t_texture	txt[4];
	t_map		map;
	t_player	player;
}	t_file;

typedef struct s_sprite
{
	t_img	*spritesheet;
	t_img	*displayimg;
	int		frame_count;
	int		current_frame;
}				t_sprite;

/*
** imgs will be an array where last element mlx_img is empty
*/
typedef struct s_mlx
{
	void			*mlx_ptr;
	t_img			**imgs;
	int				cube_size;
	t_sprite		**sprites;
	t_window		win;
	t_player		player;
	t_file			file;
	int				menu;
	t_img			*map;
	unsigned long	fcount;
}				t_mlx;

char	ft_setimages(t_mlx *mlx);
char	ft_create_window(t_mlx *mlx, int width, int height, char *title);
char	ft_free_allimg(t_mlx *mlx, void *mlx_ptr, t_img *img);

int		valdiate(char *str, t_file *file);
int		mouse_hook(int x, int y, void *param);
int		key_hook(int keycode, void *param);
int		key_press_hook(int keycode, t_mlx *param);

t_img	*rotate(t_img *img, float degree, t_mlx *mlx);

int		create_map_img(t_map *map, t_mlx *data);
int		update_map(t_map *map, t_mlx *data);
void	set_img_col(t_img *img, int width, int height, int color);
void	free_map(t_mlx *data);

/* file: main_utils.c */
int		reader(t_mlx *mlx, int argc, char **argv);
int		init_mlx_stuff(t_mlx *mlx);

#endif