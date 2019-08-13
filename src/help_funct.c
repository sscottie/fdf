/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:59:21 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/13 01:50:43 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void		ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float   color_bit(int n1, int n2, float p)
{
    if (n1 == n2)
        return(n1);
    return ((int)((float)n1 + (n2 - n1) * p));
}

float	ft_minus_color(float val, float first, float second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}