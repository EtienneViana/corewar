/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:28:09 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/18 18:37:45 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

static char	*ft_write_refresh(char *buff, size_t length)
{
	if (length != 0)
	{
		write(1, buff, length);
		ft_bzero(buff, length);
	}
	return (buff);
}

static char	*st_buff_overload(char *buff, char *str)
{
	size_t		length;
	size_t		size;
	size_t		size_tmp;

	size_tmp = 0;
	length = ft_strlen(buff);
	size = ft_strlen(str);
	if (length + size == 4096)
	{
		buff = ft_write_refresh(buff, length);
		return (buff);
	}
	while (size + length > 4096)
	{
		buff = ft_strncat(buff, str + size_tmp, 4096 - length);
		size = size - (4096 - length);
		size_tmp = size_tmp + (4096 - length);
		buff = ft_write_refresh(buff, 4096);
		length = 0;
	}
	buff = ft_strncat(buff, str + size_tmp, size);
	return (buff);
}

int			ft_fill_buff(char *str, int end)
{
	static char		*buff;
	static size_t	length_total;
	size_t			length;
	size_t			size;

	if (end == 2)
	{
		ft_strdel(&buff);
		return ((length_total = 0));
	}
	if (!buff && !(buff = ft_strnew(4096)))
		return (0);
	length = ft_strlen(buff);
	size = 0;
	if (str)
		size = ft_strlen(str);
	if (size == 0 && end == 0)
		return (0);
	if (end == 1)
		buff = ft_write_refresh(buff, length);
	else if (length + size < 4096)
		buff = ft_strncat(buff, str, size);
	else if (length + size >= 4096)
		buff = st_buff_overload(buff, str);
	return (length_total = length_total + size);
}
