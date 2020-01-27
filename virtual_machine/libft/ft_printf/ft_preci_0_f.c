/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci_0_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 10:32:37 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/08 11:48:04 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*st_alloc_hash(t_asset asset, long k, int i)
{
	char	*str;

	if (!(str = ft_strnew(i + 3)))
		return (NULL);
	if (ft_strchr(asset.flags, '#') && k != 0)
		str[i] = '.';
	else if (ft_strchr(asset.flags, '#') && k == 0)
		str[1] = '.';
	if (k == 0)
		str[0] = '0';
	return (str);
}

char		*ft_preci_0(t_asset asset, double n, long k, int i)
{
	char	*str;

	k = n * 10;
	i = ft_size_long(k) - 1;
	if (!(str = st_alloc_hash(asset, k, i)))
		return (NULL);
	if (k < 0 || 1.0 / n < 0)
	{
		k = -k;
		str[0] = '-';
		if (1.0 / n < 0)
		{
			str[1] = '0';
			if (ft_strchr(asset.flags, '#'))
				str[2] = '.';
		}
	}
	if ((n - (k / 10)) > 0.50 || (n + (k / 10)) < -0.50)
		k = (k / 10) + 1;
	else
		k = k / 10;
	k = k * 10;
	while ((k = k / 10) != 0)
		str[--i] = (k % 10) + '0';
	return (str);
}
