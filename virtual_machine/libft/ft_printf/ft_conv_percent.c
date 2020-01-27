/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:40:38 by eviana            #+#    #+#             */
/*   Updated: 2019/03/11 11:05:42 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_percent(t_asset asset, va_list ap)
{
	char			*str;
	unsigned char	c;
	size_t			width;
	size_t			j;

	j = 0;
	width = (!(asset.width) ? 1 : asset.width);
	if (!(str = ft_strnew(width)))
		return (NULL);
	c = '%';
	if (ft_strchr(asset.flags, '0') && !ft_strchr(asset.flags, '-'))
		while (j < width)
			str[j++] = '0';
	else
		while (j < width)
			str[j++] = ' ';
	if ((ft_strchr(asset.flags, '-') || width == 0) && c)
		str[0] = c;
	else
		str[--width] = c;
	(void)ap;
	return (str);
}
