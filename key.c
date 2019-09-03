/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:27:04 by croxane           #+#    #+#             */
/*   Updated: 2019/08/19 16:27:06 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		clear_image(t_struct *data)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT - 200)
	{
		x = -1;
		while (++x < WIDTH)
			data->art[x + y * WIDTH] = 0;
	}
}

int			key_mouse(int key, int x, int y, t_struct *data)
{
	if (key == 5)
		data->push *= 1.1;
	mlx_clear_window(data->mlx, data->win);
	clear_image(data);
	ft_print(data);
	if (key == 4)
		data->push /= 1.1;
	mlx_clear_window(data->mlx, data->win);
	clear_image(data);
	ft_print(data);
	return (0);
}

int			key_hook_two(int key, void *param)
{
	if (key == 126)
	{
		clear_image(param);
		ft_push_down(param);
	}
	if (key == 47)
	{
		clear_image(param);
		ft_volume_point(param);
		ft_print(param);
	}
	if (key == 0)
	{
		clear_image(param);
		ft_volume_point_y(param);
		ft_print(param);
	}
	if (key == 34)
	{
		clear_image(param);
		ft_iso(param);
		ft_print(param);
	}
	return (0);
}

int			key_hook(int key, void *param)
{
	if (key == 53)
		exit(0);
	if (key == 123)
	{
		clear_image(param);
		ft_push_left(param);
	}
	if (key == 124)
	{
		clear_image(param);
		ft_push_right(param);
	}
	if (key == 125)
	{
		clear_image(param);
		ft_push_up(param);
	}
	if (key == 49)
	{
		clear_image(param);
		ft_not_iso(param);
		ft_print(param);
	}
	key_hook_two(key, param);
	return (0);
}
