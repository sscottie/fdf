/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croxane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:14:53 by croxane           #+#    #+#             */
/*   Updated: 2019/09/01 16:14:55 by croxane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_not_iso(t_struct *data)
{
	int		i;

	i = 0;
	while (i < data->count)
	{
		data->pixel[i].x = data->def[i].x;
		data->pixel[i].y = data->def[i].y;
		data->pixel[i].z = data->def[i].z;
		data->volume[i].x = data->def[i].x;
		data->volume[i].y = data->def[i].y;
		data->volume[i].z = data->def[i].z;
		i++;
	}
}

void		ft_move_2(t_struct *data)
{
	int		i;
	int		min;

	i = -1;
	min = data->pixel[0].x;
	while (++i < data->count)
		if (data->pixel[i].x < min)
			min = data->pixel[i].x;
	i = -1;
	if (min < 0)
	{
		min *= -1;
		while (++i < data->count)
			data->pixel[i].x += min;
	}
}

void		ft_iso(t_struct *data)
{
	int		previous_x;
	int		previous_y;
	int		i;

	i = -1;
	foo(data);
	while (++i < data->count)
	{
		previous_x = data->volume[i].x;
		previous_y = data->volume[i].y;
		data->pixel[i].x = (previous_x - previous_y) / cos(0.523599);
		data->pixel[i].y = data->pixel[i].z + (previous_x + previous_y)
				/ sin(0.523599);
	}
	i = -1;
	ft_move_2(data);
	foo(data);
}
