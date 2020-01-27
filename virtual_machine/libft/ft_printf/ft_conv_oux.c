/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:32:11 by eviana            #+#    #+#             */
/*   Updated: 2019/03/04 10:08:23 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_converter(t_asset asset, char *str)
{
	char	*str2;

	str2 = str;
	if (asset.type == 21)
	{
		if (!(str = ft_convert_base(str, "0123456789", "01234567")))
			return (NULL);
		else
			free(str2);
	}
	else if (asset.type == 23)
	{
		if (!(str = ft_convert_base(str, "0123456789", "0123456789abcdef")))
			return (NULL);
		else
			free(str2);
	}
	else if (asset.type == 24)
	{
		if (!(str = ft_convert_base(str, "0123456789", "0123456789ABCDEF")))
			return (NULL);
		else
			free(str2);
	}
	return (str);
}

char	*ft_conv_oux(t_asset asset, va_list ap)
{
	char	*str;

	if ((asset.length == 1) && (!(str = ft_ultoa(va_arg(ap, unsigned long)))))
		return (NULL);
	if ((asset.length == 2)
			&& (!(str = ft_ulltoa(va_arg(ap, unsigned long long)))))
		return (NULL);
	if ((asset.length == 3)
			&& (!(str = ft_itoa((unsigned short)va_arg(ap, int)))))
		return (NULL);
	if ((asset.length == 4)
			&& (!(str = ft_itoa((unsigned char)va_arg(ap, int)))))
		return (NULL);
	if ((asset.length == 0) && (!(str = ft_utoa(va_arg(ap, unsigned int)))))
		return (NULL);
	if (!(str = ft_converter(asset, str)))
		return (NULL);
	if (!(str = ft_build_str(str, asset, 0)))
		return (NULL);
	return (str);
}
