/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 21:17:18 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/13 00:04:40 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        set_colours(t_map *map)
{
    t_vector    v;
    t_vector    *cur;

    v.y = 0;
    while (v.y < map->height)
    {
        v.x = 0;
        while (v.x < map->width)
        {
            cur = map->vectors[(int)v.y * map->width + (int)v.x];
            cur->colour = rgb(0xFF0000, 0xFFFFFF, ft_minus_color(cur->z,
                map->depth_min, map->depth_max));
            v.x++;
        }
        v.y++;
    }
}

t_vector    proj_vector(t_vector v, t_mlx *mlx)
{
    v.x -= (float)(mlx->map->width - 1) / 2.0f;
    v.y -= (float)(mlx->map->height - 1) / 2.0f;
    v.z -= (float)(mlx->map->depth_min + mlx->map->depth_max) / 2.0f;
    v = rotate(v, mlx->cam);
    v.x *= mlx->cam->zoom;
    v.y *= mlx->cam->zoom;
    v.x += mlx->cam->offset_x;
    v.y += mlx->cam->offset_y;
    return (v);
}

t_vector    vector_at(t_map *map, int x, int y)
{
    return (*map->vectors[y * map->width + x]);
}

t_vector    *get_vector(int x, int y, char *str)
{
    t_vector    *v;
    
    v = ft_memalloc(sizeof(t_vector));
    if (v == NULL)
        return (NULL);
    v->x = (float)x;
    v->y = (float)y;
    v->z = (float)ft_atoi(str);
    v->colour = 0xFFFFFF;
    return (v);
}

t_map       *get_map(int width, int height)
{
    t_map   *map;
    
    map = ft_memalloc(sizeof(t_map));
    if (map == NULL)
        return(NULL);
    map->width = width;
    map->height = height;
    map->depth_min = 0;
    map->depth_max = 0;
    map->vectors = ft_memalloc(sizeof(t_vector *) * width * height);
    if (map->vectors == NULL)
    {
        ft_memdel((void **)&map);
        return (NULL);
    }
    return (map);
}