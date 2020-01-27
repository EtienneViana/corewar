/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inf_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:17:34 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/08 11:30:45 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*st_apply_flags(t_asset asset, char *str, char *str2)
{
	size_t	i;
	int		j;

	i = -1;
	j = 0;
	if (ft_strchr(asset.flags, '+') && str2[0] == 'i')
		str[++i] = '+';
	if (ft_strchr(asset.flags, '-'))
	{
		while (str2[j])
			str[++i] = str2[j++];
		while (++i < asset.width)
			str[i] = ' ';
	}
	else
	{
		while (i + 1 < (asset.width - ft_strlen(str2))
				&& asset.width > ft_strlen(str2))
			str[++i] = ' ';
		while (str2[j])
			str[++i] = str2[j++];
	}
	return (str);
}

char		*ft_inf_f(t_asset asset, char *str2)
{
	char	*str;
	size_t	i;

	i = 0;
	if (ft_strlen(str2) > asset.width)
		i = ft_strlen(str2);
	else
		i = asset.width;
	if (ft_strchr(asset.flags, '+') && str2[0] == 'i')
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	str = st_apply_flags(asset, str, str2);
	return (str);
}
