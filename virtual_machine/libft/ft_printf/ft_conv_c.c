/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:04:48 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:35 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	st_print_null(t_asset asset)
{
	size_t		j;

	j = 1;
	if (ft_strchr(asset.flags, '0') && !ft_strchr(asset.flags, '-'))
		while (j++ < asset.width)
			ft_putchar('0');
	else if (!ft_strchr(asset.flags, '-'))
		while (j++ < asset.width)
			ft_fill_buff(" ", 0);
	ft_fill_buff(" ", 1);
	ft_putchar('\0');
	if (ft_strchr(asset.flags, '-'))
		while (j++ < asset.width)
			ft_fill_buff(" ", 0);
}

char		*ft_conv_c(t_asset asset, va_list ap)
{
	char			*str;
	unsigned char	c;
	size_t			width;
	size_t			j;

	j = 0;
	if (!(width = asset.width))
		width++;
	str = ft_strnew(width);
	c = va_arg(ap, int);
	if (ft_strchr(asset.flags, '0')
			&& !ft_strchr(asset.flags, '-') && c != '\0')
		while (j < width)
			str[j++] = '0';
	else if (c != '\0')
		while (j < width)
			str[j++] = ' ';
	if (c == '\0')
		(st_print_null(asset));
	if ((ft_strchr(asset.flags, '-') || width == 0) && c)
		str[0] = c;
	else
		str[--width] = c;
	return (str);
}
