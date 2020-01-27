/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:05:22 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/06 16:13:37 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*st_width_preci(t_asset asset, char *str, int i, int j)
{
	char	*str2;
	int		k;

	k = -1;
	if (i < j && i != 0)
		i = j;
	if (!(str2 = ft_strnew(i + 1)))
		return (NULL);
	if (ft_strchr(asset.flags, '-') || i == j)
	{
		while (++k < j)
			str2[k] = str[k];
		while (k < i)
			str2[k++] = ' ';
	}
	else
	{
		while (--j >= 0)
			str2[--i] = str[j];
		while (i > 0 && ft_strchr(asset.flags, '0'))
			str2[--i] = '0';
		while (i > 0 && !ft_strchr(asset.flags, '0'))
			str2[--i] = ' ';
	}
	return (str2);
}

static char	*ft_add_0x(char *initial, int i, t_asset asset)
{
	char	*str;

	if (!(str = ft_strnew(i + 3)))
		return (NULL);
	i++;
	if (!ft_strchr(asset.flags, '0'))
	{
		while (--i >= 0)
			str[i + 2] = initial[i];
		str[0] = '0';
		str[1] = 'x';
	}
	else
	{
		str[i] = '0';
		str[i + 1] = 'x';
		while (--i >= 0)
			str[i + 2] = initial[i];
	}
	ft_strdel(&initial);
	return (str);
}

static char	*st_conv(long adr)
{
	int		i;
	char	*str;
	char	*base;
	long	tmp;

	i = 0;
	tmp = adr;
	base = "0123456789abcdef";
	while ((tmp / 16) > 0)
	{
		tmp /= 16;
		i++;
	}
	if (!(str = ft_strnew(i + 2)))
		return (NULL);
	i = 0;
	while ((adr / 16) > 0)
	{
		str[i++] = base[(adr % 16)];
		adr /= 16;
	}
	str[i] = base[(adr % 16)];
	return (str);
}

char		*ft_conv_p(t_asset asset, va_list ap)
{
	char	*final;
	char	*additional;
	size_t	i;

	if (!(final = st_conv(va_arg(ap, long))))
		return (NULL);
	i = ft_strlen(final) - 1;
	if (i < asset.width)
	{
		if (!(additional = ft_add_0x(ft_strrev(final), i, asset)))
			return (NULL);
		if (!(final = st_width_preci(asset, additional, asset.width, i + 3)))
		{
			free(additional);
			return (NULL);
		}
		ft_strdel(&additional);
	}
	else
		final = ft_add_0x(ft_strrev(final), i, asset);
	return (final);
}
