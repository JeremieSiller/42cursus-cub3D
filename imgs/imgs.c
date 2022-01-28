/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiller <jsiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:45:24 by nschumac          #+#    #+#             */
/*   Updated: 2021/10/01 15:43:04 by jsiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../render/render.h"

/*
** sets img to one color
*/
void	set_img_col(t_img *img, int width, int height, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			ft_putpixelimg(img, i, j, color);
			j++;
		}
		i++;
	}
}

/*
** Creates a new mlx_img
** the image is malloced and set
*/
t_img	*ft_new_mlx_img(void *mlx, int width, int height)
{
	t_img	*ret;

	ret = (t_img *)malloc(sizeof(t_img));
	if (!ret)
		return (NULL);
	ret->img_ptr = mlx_new_image(mlx, width, height);
	if (!ret->img_ptr)
	{
		free(ret);
		return (NULL);
	}
	ret->width = width;
	ret->height = height;
	ret->data.data_addr = mlx_get_data_addr(ret->img_ptr, &ret->data.bpp,
			&ret->data.size_line, &ret->data.endian);
	if (!ret->data.data_addr)
	{
		mlx_destroy_image(mlx, ret->img_ptr);
		free(ret);
		return (NULL);
	}
	return (ret);
}

/*
** Creates a new mlx_img that comes from a xpm file
** the image is malloced and set
*/
t_img	*ft_new_xpm(void *mlx, char *path)
{
	t_img	*ret;

	ret = (t_img *)malloc(sizeof(t_img));
	if (!ret)
		return (NULL);
	ret->img_ptr = mlx_xpm_file_to_image(mlx,
			path, &ret->width, &ret->height);
	if (!ret->img_ptr)
	{
		free(ret);
		return (NULL);
	}
	ret->data.data_addr = mlx_get_data_addr(ret->img_ptr, &ret->data.bpp,
			&ret->data.size_line, &ret->data.endian);
	if (!ret->data.data_addr)
	{
		mlx_destroy_image(mlx, ret->img_ptr);
		free(ret);
		return (NULL);
	}
	return (ret);
}

/*
** if img is NULL it will delete all images in mlx
** if not it will only destroy and free that image
** if a mlx pointer is passed it will use that
** if not it will use the mlx mlxptr
*/
char	ft_free_allimg(t_mlx *mlx, void *mlx_ptr, t_img *img)
{
	int	c;

	if (img)
	{
		if (mlx_ptr)
			mlx_destroy_image(mlx_ptr, img->img_ptr);
		else
			mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
		free(img);
		return (1);
	}
	c = 0;
	while (mlx->imgs[c])
	{
		if (mlx->imgs[c]->img_ptr)
			mlx_destroy_image(mlx->mlx_ptr, mlx->imgs[c]->img_ptr);
		free(mlx->imgs[c]);
		c++;
	}
	free(mlx->imgs);
	return (1);
}

char	ft_setimages(t_mlx *mlx)
{
	mlx->imgs = (t_img **)ft_calloc(7, sizeof(t_img *));
	if (!mlx->imgs)
		return (0);
	mlx->imgs[0] = ft_new_mlx_img(mlx->mlx_ptr,
			mlx->win.width, mlx->win.height);
	if (!mlx->imgs[0] && ft_free_allimg(mlx, NULL, NULL))
		return (0);
	mlx->imgs[1] = ft_new_xpm(mlx->mlx_ptr, mlx->file.txt[0].path);
	if (!mlx->imgs[1] && ft_free_allimg(mlx, NULL, NULL))
		return (0);
	mlx->cube_size = mlx->imgs[1]->width;
	mlx->imgs[2] = ft_new_xpm(mlx->mlx_ptr, mlx->file.txt[1].path);
	if (!mlx->imgs[2] && ft_free_allimg(mlx, NULL, NULL))
		return (0);
	mlx->imgs[3] = ft_new_xpm(mlx->mlx_ptr, mlx->file.txt[2].path);
	if (!mlx->imgs[3] && ft_free_allimg(mlx, NULL, NULL))
		return (0);
	mlx->imgs[4] = ft_new_xpm(mlx->mlx_ptr, mlx->file.txt[3].path);
	if (!mlx->imgs[4] && ft_free_allimg(mlx, NULL, NULL))
		return (0);
	mlx->imgs[5] = ft_new_mlx_img(mlx->mlx_ptr,
			mlx->win.width, mlx->win.height);
	if (!mlx->imgs[5] && ft_free_allimg(mlx, NULL, NULL))
		return (5);
	return (1);
}
