/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:26:11 by eviana            #+#    #+#             */
/*   Updated: 2019/03/04 11:16:37 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_di(t_asset asset, va_list ap)
{
	char	*str;

	if ((asset.length == 1) && (!(str = ft_ltoa(va_arg(ap, long int)))))
		return (NULL);
	if ((asset.length == 2) && (!(str = ft_lltoa(va_arg(ap, long long)))))
		return (NULL);
	if ((asset.length == 3) && (!(str = ft_itoa((short)va_arg(ap, int)))))
		return (NULL);
	if ((asset.length == 4) && (!(str = ft_itoa((char)va_arg(ap, int)))))
		return (NULL);
	if ((asset.length == 0) && (!(str = ft_itoa(va_arg(ap, int)))))
		return (NULL);
	if (!(str = ft_build_str(str, asset, 1)))
		return (NULL);
	return (str);
}
