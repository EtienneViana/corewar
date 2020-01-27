/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:28:13 by eviana            #+#    #+#             */
/*   Updated: 2019/03/18 15:32:04 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_preparewidth(char *processed, t_asset asset, int signmode)
{
	if ((asset.type == 23 || asset.type == 24) && ft_strchr(asset.flags, '#')
			&& !ft_strallchr(processed, '0'))
	{
		if (!(processed = sp_strnjoin((asset.type == 23 ? "0x" : "0X"),
						processed, ft_strlen(processed), 1)))
			return (NULL);
	}
	else if (signmode == 1)
	{
		if (ft_strchr(asset.flags, '+'))
		{
			if (!(processed =
						sp_strnjoin("+", processed, ft_strlen(processed), 1)))
				return (NULL);
		}
		else if (ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '-'))
			if (!(processed =
						sp_strnjoin(" ", processed, ft_strlen(processed), 1)))
				return (NULL);
	}
	return (processed);
}

static size_t	st_set_length(char *initial, t_asset asset, int signmode)
{
	size_t	length;

	length = (asset.width > ft_strlen(initial) ?
			asset.width - ft_strlen(initial) : 0);
	if (length == 0 && ft_strchr(asset.flags, ' ')
			&& !ft_strchr(asset.flags, '-')
			&& !ft_strchr(asset.flags, '+') && signmode == 1)
		length++;
	return (length);
}

char			*ft_set_width(char *initial, t_asset asset, int signmode)
{
	size_t	length;
	char	*add;

	length = st_set_length(initial, asset, signmode);
	if (!(add = ft_strnew(length)))
		return (NULL);
	if (length && ft_strchr(asset.flags, '0')
			&& !ft_strchr(asset.flags, '-') && asset.precision == -1)
	{
		add = ft_memset(add, '0', length);
		if (ft_strchr(asset.flags, '+') || signmode == -1)
		{
			add[0] = (signmode == -1 ? '-' : '+');
			initial[0] = (signmode && length > 0 ? '0' : initial[0]);
		}
		else if (ft_strchr(asset.flags, ' '))
			add[0] = ' ';
	}
	else
		add = ft_memset(add, ' ', length);
	return (add);
}

char			*ft_addbuild(char *initial, char *add, t_asset asset)
{
	char *build;

	if (ft_strchr(asset.flags, '-'))
	{
		if (!(build = sp_strnjoin(initial, add, ft_strlen(add), 0)))
		{
			ft_strdel(&add);
			ft_strdel(&initial);
			return (NULL);
		}
	}
	else if (!(build = sp_strnjoin(add, initial, ft_strlen(initial), 1)))
	{
		ft_strdel(&add);
		ft_strdel(&initial);
		return (NULL);
	}
	return (build);
}
