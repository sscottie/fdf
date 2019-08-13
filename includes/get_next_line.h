/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscottie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:33:06 by sscottie          #+#    #+#             */
/*   Updated: 2019/05/10 15:33:08 by sscottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8

# include "fcntl.h"
# include "libft/libft.h"

int		ft_new_line(char **s, char **line, int fd, int ret);
int		get_next_line(const int fd, char **line);

#endif
