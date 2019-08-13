/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:23:57 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/13 01:47:42 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_h
# define WIN_WIDTH      1980
# define WIN_HEIGHT     1280
#include "libft.h"
#include <fcntl.h>
#include "mlx.h"

typedef struct          s_cam
{
    float   offset_x;
    float   offset_y;
    float   x;
    float   y;
    int     zoom;
    float   **matrix;
}                       t_cam;
typedef struct          s_vector
{
    float   x;
    float   y;
    float   z;
    int     colour;
}                       t_vector;

typedef struct          s_map 
{
    int         width;
    int         height;
    int         depth_min;
    int         depth_max;
    t_vector    **vectors;
}                       t_map;

typedef struct          s_image
{
    void    *image;
    char    *ptr;
    int     bpp;
    int     stride;
    int     endian;
}                       t_image;

typedef struct          s_mlx 
{
    void    *mlx;
    void    *window;
    t_image *image;
    t_map   *map;
    t_cam   *cam;
    float   **tmp;
}                       t_mlx;

typedef struct          s_line
{
    t_vector    start;
    t_vector    end;
    int         x0;
    int         y0;
    int         x1;
    int         y1;
    int         err;
    int         err_2;
}                       t_line;

t_vector	rotate(t_vector p, t_cam *r);
t_vector    proj_vector(t_vector v, t_mlx *mlx);
t_vector    vector_at(t_map *map, int x, int y);
int         hook_keypush(int key, t_mlx *mlx);
int		    line_draw(t_vector *p1, t_vector *p2);
float	    ft_minus_color(float val, float first, float second);
void	    image_set_pixel(t_image *image, int x, int y, int color);

#endif