/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:38:09 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/18 17:40:00 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_asset		ft_digest(char *tab)
{
	t_asset	asset;

	if (!(asset.flags = ft_findflags(tab)))
	{
		asset.type = -1;
		return (asset);
	}
	asset.width = ft_findwidth(tab);
	asset.precision = ft_findprecision(tab);
	asset.length = ft_findlength(tab);
	asset.type = ft_findtype(tab);
	if (!(asset.copy = ft_strsub(tab, 0, ft_strlen(tab))))
		asset.copy = ft_strnew(0);
	return (asset);
}

static void	st_assetdel(t_asset asset)
{
	ft_strdel(&asset.flags);
	ft_strdel(&asset.copy);
}

static void	st_dispatch(t_asset asset, size_t n, va_list ap)
{
	char	*(*list_ft[8])(t_asset, va_list);
	char	*str;

	list_ft[0] = &ft_noconv;
	list_ft[1] = &ft_conv_di;
	list_ft[2] = &ft_conv_oux;
	list_ft[3] = &ft_conv_c;
	list_ft[4] = &ft_conv_s;
	list_ft[5] = &ft_conv_p;
	list_ft[6] = &ft_conv_f;
	list_ft[7] = &ft_conv_percent;
	str = list_ft[n](asset, ap);
	ft_fill_buff(str, 0);
	free(str);
}

int			ft_pre_dispatch(char **tab, va_list ap)
{
	t_asset	asset;
	size_t	n;
	int		i;

	i = -1;
	while (tab[++i])
	{
		if ((n = ft_findtype(tab[i])) == -1)
			return (-1);
		n = (n == 21 || n == 22 || n == 23 || n == 24 ? 2 : n);
		asset = ft_digest(tab[i]);
		if (asset.type == -1)
		{
			st_assetdel(asset);
			return (0);
		}
		st_dispatch(asset, n, ap);
		st_assetdel(asset);
	}
	return (ft_fill_buff("", 1));
}
