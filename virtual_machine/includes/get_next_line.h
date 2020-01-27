/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:20:10 by anrzepec          #+#    #+#             */
/*   Updated: 2018/11/23 17:18:41 by andrewrze        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FD_SIZE 5000
# define BUFF_SIZE 4900
# define MAX_STACK_SIZE 65532

# include "libft.h"
# include <fcntl.h>

int		get_next_line(const int fd, char **line);

#endif
