/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:36:36 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/13 01:52:53 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

static int  clean_map(t_list **lst, t_map **map)
{
    t_list  *next;

    while (*lst)
    {
        next = (*lst)->next;
        ft_memdel(&(*lst)->content);
        ft_memdel((void **)lst);
        *lst = next;
    }
    if (map && *map)
    {
        ft_memdel((void **)&(*map)->vectors);
        ft_memdel((void **)map);
    }
    return (0);
}

static int	get_lines(int fd, t_list **lst)
{
	t_list	*temp;
	int		expected;
	char	*line;
	int		ret;

	expected = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		if (expected == -1)
			expected = (int)ft_countwords(line, ' ');
		temp = ft_lstnew(line, ft_strlen(line) + 1);
		if ((temp) == NULL)
			return (clean_map(lst, NULL));
		ft_lstadd(lst, temp);
		if (expected != (int)ft_countwords(line, ' '))
			return (clean_map(lst, NULL));
		ft_strdel(&line);
	}
	if (expected == -1 || ret == -1)
		return (clean_map(lst, NULL));
	ft_lstrev(lst);
	return (1);
}

void        find_depth(t_map *map)
{
    int         min;
    int         max;
    t_vector    v;
    t_vector    cur;

    max = 2147483647;
    min = -2147483648;
    v.y = 0;
    while (v.y < map->height)
    {
        v.x = 0;
        while (v.x < map->width)
        {
            cur = *map->vectors[(int)v.y * map->width + (int)v.x];
            if (cur.z < max)
                max = cur.z;
            if (cur.z > min)
                min = cur.z;
            v.z++;
        }
        v.y++;
    }
    map->depth_max = max;
    map->depth_min = min;
}

static int  fill_map(t_map **map, t_list *list)
{
    t_list  *lst;
    char    **split;
    int     x;
    int     y;

    lst = list;
    y = 0;
    while (y < (*map)->height)
    {
        x = 0;
        if ((split = ft_strsplit(lst->content, ' ')) == NULL)
            return (clean_map(&lst, map));
        while (x < (*map)->width)
        {
            (*map)->vectors[y * (*map)->width + x] = get_vector(x, y, split[x]);
            x++;
        }
        lst = lst->next;
        y++;
    }
    find_depth(*map);
    set_colours(*map);
    clean_map(&list, NULL);
    return (1);    
}

int     read_file(int fd, t_map **map)
{
    t_list  *lst;

    lst = NULL;
    if (!(get_lines(fd, &lst)))
        return (0);
    *map = get_map(ft_countwords(lst->content, ' '), ft_lstcount(lst));
    if (*map == NULL)
    {
        return (clean_map(&lst, map));
    return(fill_map(map,lst));
    }
}