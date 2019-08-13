/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:58:24 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/12 23:59:16 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_vector	rotate(t_vector p, t_cam *r)
{
	t_vector	v;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = -sin(r->y) * x + cos(r->y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.colour = p.colour;
	return (v);
}