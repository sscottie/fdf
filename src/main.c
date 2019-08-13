/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <sscottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:54:47 by sscottie          #+#    #+#             */
/*   Updated: 2019/08/13 00:11:07 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int     prt_error(char *s)
{
    ft_putendl(s);
    return (1);
}

int     main(int argc, char **argv)
{
    int     fd;
    t_map   *map;
    t_mlx   *mlx;    
    
    if (argc < 2)
        return (error("error: need more arguments (aka zikkurats)"));
    fd = open(argv[1], O_RDONLY);
    if (fd < 0 || !read_file(fd, &map))
        return (prt_error("error: invalid file - cure it!"));
    if ((mlx = init(ft_strjoin("FdF - ", argv[1]))) == NULL)
        return (error("error: can't init"));
    mlx->map = map;
    render(mlx);
    mlx_key_hook(mlx->window, hook_keypush, mlx);
    
    return 0;
}