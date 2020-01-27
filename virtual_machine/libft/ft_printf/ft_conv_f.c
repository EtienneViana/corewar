/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:01:42 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/18 18:45:39 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_precision(t_asset asset, char *str)
{
	int		j;
	int		i;

	i = 0;
	while (str[i] != '.')
		i++;
	j = i;
	if (asset.precision < 16)
	{
		ft_bzero(str + i + asset.precision + 2, 16 - asset.precision);
		if (str[i + asset.precision + 1] > '4')
		{
			while (str[j + asset.precision] == '9')
				str[j-- + asset.precision] = '0';
			str[j + asset.precision] = str[asset.precision + j] + ('b' - 'a');
		}
	}
	else
		while (i + 16 < asset.precision + j)
			str[i++ + 17] = '0';
	str[i + asset.precision + 1] = '\0';
	return (str);
}

static char		*st_conv(char *str, long k, double n, int s)
{
	unsigned long	j;
	int				i;

	n = n - k;
	i = 0;
	j = n * sp_power(10, 17);
	while (i < 17)
	{
		str[i++] = (j % 10) + '0';
		j = j / 10;
	}
	str[i++] = '.';
	if (k == 0)
		str[i++] = '0';
	while (k != 0)
	{
		str[i++] = (k % 10) + '0';
		k = k / 10;
	}
	if (s == 1)
		str[i++] = '-';
	ft_bzero(str + i, ft_strlen(str + i));
	return (ft_strrev(str));
}

static char		*ft_ftoa(double n)
{
	int		i;
	char	*str;

	i = 0;
	if (n == 0)
	{
		if (!(str = ft_strnew(20)))
			return (NULL);
		if (1.0 / n < 0)
			str[i++] = '-';
		str[i++] = '0';
		str[i++] = '.';
		while (i < 19)
			str[i++] = '0';
		return (str);
	}
	if (n < 0 || 1.0 / n < 0)
	{
		n = -n;
		i = 1;
	}
	if (!(str = ft_strnew(ft_size_long(n) + 19 + i + 2)))
		return (NULL);
	str = st_conv(str, n, n, i);
	return (str);
}

char			*ft_conv_f(t_asset asset, va_list ap)
{
	char		*str;
	long double	n;

	if (asset.length == 5)
		n = va_arg(ap, long double);
	else
		n = va_arg(ap, double);
	if (asset.precision == -1)
		asset.precision = 6;
	if (n == 1.0 / 0.0)
		return (str = ft_inf_f(asset, "inf"));
	if (n == -1.0 / 0.0)
		return (str = ft_inf_f(asset, "-inf"));
	if (n != n)
		return (str = ft_inf_f(asset, "nan"));
	else if (asset.precision == 0)
		str = ft_preci_0(asset, n, 0, 0);
	else
	{
		str = ft_ftoa(n);
		str = ft_precision(asset, str);
	}
	str = ft_width_f(asset, str, asset.width, ft_strlen(str));
	return (str);
}
