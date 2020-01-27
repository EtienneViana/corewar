/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:19:12 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/18 15:33:27 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_set_precision_o(char *initial, t_asset *asset)
{
	if (asset->type == 21 && ft_strchr(asset->flags, '#'))
	{
		if (!(asset->precision == -1 && ft_strchr(asset->flags, '0')
				&& asset->width > ft_strlen(initial))
				&& !((asset->precision == -1 || asset->precision == 0)
				&& ft_atoi(initial) == 0))
			asset->precision = (asset->precision < (int)(ft_strlen(initial))
				? ft_strlen(initial) + 1 : asset->precision);
		else if (asset->precision == 0 && ft_strchr(asset->flags, '#')
				&& ft_atoi(initial) == 0)
			asset->precision = 1;
	}
}

char			*ft_set_precision(char *initial, t_asset *asset, int signmode)
{
	size_t	l;
	size_t	length;
	char	*add;

	ft_set_precision_o(initial, asset);
	if (asset->precision > 0)
	{
		l = ft_strlen(initial) - (signmode == -1 ? 1 : 0);
		length = ((size_t)asset->precision > l ? asset->precision - l : 0);
		if (!(add = ft_strnew(length)))
			return (NULL);
		add = ft_memset(add, '0', length);
		if (signmode == -1 && length > 0)
		{
			add[0] = '-';
			initial[0] = '0';
		}
		return (add);
	}
	return (ft_strnew(0));
}

static char		*st_set_x_case(char *final)
{
	int		i;
	char	*str;

	i = 0;
	if ((str = ft_strchr(final, 'x')))
	{
		str[0] = '0';
		str = ft_strchr(final, '0');
		str[1] = 'x';
	}
	else if ((str = ft_strchr(final, 'X')))
	{
		str[0] = '0';
		str = ft_strchr(final, '0');
		str[1] = 'X';
	}
	return (final);
}

static char		*ft_init_final(char *initial, char *add, t_asset asset)
{
	char *final;

	if (!(asset.precision == 0 && ft_atoi(initial) == 0)
			|| ((asset.type == 23 || asset.type == 24)
				&& !ft_strallchr(initial, '0')))
	{
		if (!(final = ft_strjoin(add, initial)))
			return (NULL);
	}
	else if (!(final = ft_strnew(0)))
		return (NULL);
	return (final);
}

char			*ft_build_str(char *initial, t_asset asset, int signmode)
{
	char	*add;
	char	*final;

	if (signmode)
		signmode = (initial[0] == '-' ? -1 : 1);
	if (!(add = ft_set_precision(initial, &asset, signmode)))
		return (NULL);
	if (!(final = ft_init_final(initial, add, asset)))
		return (NULL);
	if (!(final = ft_preparewidth(final, asset, signmode)))
		return (NULL);
	ft_strdel(&add);
	if (!(add = ft_set_width(final, asset, signmode)) ||
		!(final = ft_addbuild(final, add, asset)))
		return (NULL);
	if ((asset.type == 23 || asset.type == 24) && ft_strchr(asset.flags, '#'))
		st_set_x_case(final);
	ft_strdel(&add);
	ft_strdel(&initial);
	return (final);
}
