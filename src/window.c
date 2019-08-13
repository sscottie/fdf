/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:23:17 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/12 23:45:05 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx       *mlxdel(t_mlx *mlx)
{
    if (mlx->window != NULL)
        mlx_destroy_window(mlx->mlx, mlx->window);
    if (mlx->cam != NULL)
        ft_memdel((void **)&mlx->cam);
    if (mlx->image != NULL)
        ft_memdel((void **)&mlx->image);
    ft_memdel((void **)&mlx);
    return (NULL);
}

t_mlx       *init(char *title)
{
    t_mlx   *mlx;
    
    if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
        return(NULL);
    if ((mlx->mlx = mlx_init()) == NULL ||
        (mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
            WIN_HEIGHT, title)) == NULL ||
        (mlx->cam = ft_memalloc(sizeof(t_cam))) == NULL ||
        (mlx->image = new_image(mlx)) == NULL)
        return (mlxdel(mlx));
    mlx->cam->x = 0.5;
    mlx->cam->y = 0.5;
    mlx->cam->zoom = 32;
    mlx->cam->offset_x = WIN_WIDTH / 2;
    mlx->cam->offset_y = WIN_HEIGHT / 2;
    return (mlx);
}