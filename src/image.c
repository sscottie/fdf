/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:30:36 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/13 01:42:03 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(image->ptr + ((x + y * WIN_WIDTH) * image->bpp)) = color;
}

void    clear_image(t_image *image)
{
    ft_bzero(image->ptr, WIN_WIDTH * WIN_HEIGHT * image->bpp);
}

t_image *del_image(t_mlx *mlx, t_image *img)
{
    if (img != NULL)
    {
        if (img->image != NULL)
            mlx_destroy_image(mlx->mlx, img->image);
        ft_memdel((void **)&img);
    }
}

t_image *new_image(t_mlx *mlx)
{
    t_image     *img;

    if ((img = ft_memalloc(sizeof(t_image))) == NULL)
        return (NULL);
    if ((img->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT)) == NULL)
        return (del_image(mlx, img));
    img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
        &img->endian);
    img->bpp /= 8;
    return (img);
}