/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:30:31 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/06 18:12:01 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	sp_power(long nb, int power)
{
	if (power > 1)
		return (nb * sp_power(nb, (power - 1)));
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb);
}

char			*sp_strnjoin(char *s1, char *s2, size_t n, int mode)
{
	char	*str;

	if (!s1 || !s2 || !(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		if (mode == 2)
		{
			ft_strdel(&s1);
			ft_strdel(&s2);
		}
		else
			(mode == 0 ? ft_strdel(&s1) : ft_strdel(&s2));
		return (NULL);
	}
	str = ft_strcpy(str, s1);
	str = ft_strncat(str, s2, n);
	if (mode == 2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	else
		(mode == 0 ? ft_strdel(&s1) : ft_strdel(&s2));
	return (str);
}
