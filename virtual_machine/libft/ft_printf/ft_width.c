/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:29:05 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/08 10:59:39 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_alloc(int i, int j)
{
	char	*str;

	if (i > j)
	{
		if (!(str = ft_strnew(i + 1)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strnew(j + 1)))
			return (NULL);
	}
	return (str);
}

static char	*st_left_align(t_asset asset, char *str, int i, int j)
{
	int		n;
	int		k;
	char	*str2;

	n = 0;
	k = -1;
	if (!(str2 = ft_alloc(i, j)))
		return (NULL);
	if (i < j)
		i = j;
	if (ft_strchr(asset.flags, '-') || i == j)
	{
		if (ft_strchr(asset.flags, '+') && !ft_strchr(str, '-'))
			str2[n++] = '+';
		else if (ft_strchr(asset.flags, ' ') && !ft_strchr(str, '-'))
			str2[n++] = ' ';
		while (++k < j)
			str2[k + n] = str[k];
		while (k + n < i)
			str2[k++ + n] = ' ';
	}
	return (str2);
}

static char	*st_apply_flags(t_asset asset, char *str, char *str2, int n)
{
	if (ft_strchr(asset.flags, '+') && ft_strchr(asset.flags, '0')
			&& !ft_strchr(str, '-'))
		str2[0] = '+';
	else if (ft_strchr(asset.flags, '+') && !ft_strchr(str, '-'))
		str2[n - 1] = '+';
	else if (ft_strchr(str, '-') && ft_strchr(asset.flags, '0'))
	{
		str2[0] = '-';
		str2[n] = '0';
	}
	else if (ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '0') &&
			!ft_strchr(str, '-'))
		str2[0] = ' ';
	return (str2);
}

static char	*st_right_align(t_asset asset, char *str, int i, int j)
{
	int		k;
	int		n;
	char	*str2;

	if (!(str2 = ft_alloc(i, j)))
		return (NULL);
	n = i - j;
	k = i;
	while (--j >= 0)
		str2[--k] = str[j];
	while (k > 0)
	{
		if (ft_strchr(asset.flags, '0'))
			str2[--k] = '0';
		else
			str2[--k] = ' ';
	}
	str2 = st_apply_flags(asset, str, str2, n);
	return (str2);
}

char		*ft_width_f(t_asset asset, char *str, int i, int j)
{
	char	*str2;
	int		k;
	int		n;

	n = 0;
	k = -1;
	if (i < j)
		i = j;
	if (ft_strchr(asset.flags, '-') || i == j)
	{
		if (!(str2 = st_left_align(asset, str, i, j)))
			return (NULL);
	}
	else
	{
		if (!(str2 = st_right_align(asset, str, i, j)))
			return (NULL);
	}
	free(str);
	return (str2);
}
