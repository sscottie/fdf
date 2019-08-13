/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:57:49 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/13 01:47:08 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     rgb(int c1, int c2, float p)
{
    int r;
    int g;
    int b;

    if (c1== c2)
        return(c1);
    r = color_bit((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
    g = color_bit((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
    b = color_bit(c1 & 0xFF, c2 & 0xFF, p);
    return (r << 16 | g << 8 | b);
}

int         line_process_point(t_mlx *mlx, t_line *l, t_vector *p1,
        t_vector *p2)
{
    float   percent;

    if (p1->x < 0 || p1->x >= WIN_WIDTH || p1->y < 0 || p1->y >= WIN_HEIGHT
        || p2->x < 0 || p2->x >= WIN_WIDTH || p2->y < 0 || p2->y >= WIN_HEIGHT)
        return (1);
    percent = (l->x0 > l->y0 ?
            ft_minus_color((int)p1->x, (int)l->start.x, (int)l->end.x)
            : ft_minus_color((int)p1->y, (int)l->start.y, (int)l->end.y));
    image_set_pixel(mlx->image, (int)p1->x, (int)p1->y, rgb(p1->colour, p2->colour, 
                percent));
    l->err_2 = l->err;
    if (l->err_2 > -l->x0)
    {
        l->err -= l->y0;
        p1->x += l->x1;
    }
    if (l->err_2 < l->x0)
    {
        l->err += l->x0;
        p1->y += l->y1;
    }
    return (0);
}

void        line(t_mlx *mlx, t_vector p1, t_vector p2)
{
    t_line      line;

    p1.x = (int)p1.x;
    p2.x = (int)p2.x;
    p1.y = (int)p1.y;
    p2.y = (int)p2.y;
    line.start = p1;
    line.end = p2;
    if (!line_draw(&p1, &p2))
        return (0);
    line.x0 = (int)ft_abs((int)p2.x - (int)p1.x);
    line.x1 = (int)p1.x < (int)p2.x ? 1 : -1;
    line.y0 = (int)ft_abs((int)p2.y - (int)p1.y);
    line.y1 = (int)p1.y < ((int)p2.y ? 1 : -1);
    line.err = (line.x0 > line.y0 ? line.x0 : -line.y0) / 2;
    while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
        if (line_process_point(mlx, &line, &p1, &p2))
            break ;
}

void        render(t_mlx *mlx)
{
    int         x;
    int         y;
    t_vector    v;
    t_map       *map;

    map = mlx->map;
    clear_image(mlx->image);
    x = 0;
    while (x < map->width)
    {
        y = 0;
        while (y < map->height)
        {
            v = proj_vector(vector_at(map, x, y), mlx);
            if (x + 1 < map->width)
                line(mlx, v, proj_vector(vector_at(map, x + 1, y), mlx));
            if (y + 1 < map->height)
                line(mlx, v, proj_vector(vector_at(map, x, y + 1), mlx));
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
}