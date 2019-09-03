/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:31:44 by croxane           #+#    #+#             */
/*   Updated: 2019/09/03 15:56:33 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_swap(int *a, int *b)
{
	int		t;

	t = *a;
	*a = *b;
	*b = t;
}

void		ft_init(t_print *print, t_struct *data, int i)
{
	print->width = WIDTH;
	print->heigth = HEIGHT - 200;
	print->x0 = data->pixel[i].x * data->push;
	print->y0 = data->pixel[i].y * data->push;
}

void		ft_bresenhamline_part_2(t_print *print,
		t_struct *data, int x1, int y1)
{
	int i;

	i = print->i;
	print->dx = x1 - print->x0;
	print->error = print->dx / 2;
	print->dy = abs(y1 - print->y0);
	print->ystep = (print->y0 < y1) ? 1 : -1;
	print->y = print->y0;
	print->x = print->x0;
	while (print->x <= x1 && print->x < print->width && print->x >= -data->zoom
		&& print->y < print->heigth && print->y >= 0)
	{
		if (print->x >= 0 && print->y >= 0 && print->x < print->width && print->y < print->heigth)
			data->art[(print->steep ? print->y : print->x)
			+ (print->steep ? print->x : print->y)
			* WIDTH] = data->pixel[i].colour;
		print->error -= print->dy;
		if (print->error < 0)
		{
			print->y += print->ystep;
			print->error += print->dx;
		}
		print->x++;
	}
	free(print);
}

void		ft_bresenhamline(int x1, int y1, t_struct *data, int i)
{
	t_print *print;

	print = (t_print*)malloc(sizeof(t_print));
	ft_init(print, data, i);
	print->steep = abs(y1 - print->y0) > abs(x1 - print->x0);
	if (print->steep)
	{
		print->width = HEIGHT - 200;
		print->heigth = WIDTH;
		ft_swap(&print->x0, &print->y0);
		ft_swap(&x1, &y1);
	}
	if (print->x0 > x1)
	{
		ft_swap(&print->x0, &x1);
		ft_swap(&print->y0, &y1);
	}
	print->i = i;
	ft_bresenhamline_part_2(print, data, x1, y1);
}

void		ft_print(struct s_struct *data)
{
	int		i;
	int		length;

	length = data->length;
	i = data->count;
	while (--i)
	{
		if (data->pixel[i].x > data->pixel[i - 1].x)
			ft_bresenhamline(data->pixel[i - 1].x
			* data->push, data->pixel[i - 1].y
			* data->push, data, i);
		if (i >= length && data->pixel[i].y > data->pixel[i - length].y)
			ft_bresenhamline(data->pixel[i - length].x * data->push,
					data->pixel[i - length].y
			* data->push, data, i);
	}
	mlx_clear_window(data->mlx, data->win);
	ft_menu(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
