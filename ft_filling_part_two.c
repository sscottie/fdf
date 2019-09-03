/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filling_part_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:49:36 by sscottie          #+#    #+#             */
/*   Updated: 2019/09/03 17:03:58 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_move(struct s_struct *data)
{
	int		i;

	i = -1;
	while (++i < data->count)
	{
		data->pixel[i].x *= (int)data->zoom;
		data->pixel[i].y *= (int)data->zoom;
		data->pixel[i].z *= (int)data->zoom;
	}
}

void		ft_print_mistake(void)
{
	write(1, "This map isn't valid. Fix the map!!!", 36);
	exit(0);
}

void		ft_check_colour_two(struct s_struct *data, int i)
{
	if (!data->pixel[i].colour)
	{
		if (data->pixel[i].z < 0)
			data->pixel[i].colour = 0x23efff * abs(data->pixel[i].z - 1);
		else
			data->pixel[i].colour = 0xcdff00 * abs(data->pixel[i].z + 1);
	}
}

void		ft_coor(t_coor *coor)
{
	coor->x = 0;
	coor->y = 0;
	coor->i = 0;
}
