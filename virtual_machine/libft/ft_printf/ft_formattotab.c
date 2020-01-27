/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formattotab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:46:34 by eviana            #+#    #+#             */
/*   Updated: 2019/03/09 16:22:32 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_isconv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f'
			|| c == '%')
		return (1);
	return (0);
}

unsigned int	ft_partsnbr(const char *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] != '%')
			i++;
		k = ((i != 0) ? k + 1 : k);
		if (s[i] && s[i] == '%')
		{
			j++;
			while (s[i + j] && !ft_isconv(s[i + j]))
				j++;
		}
		if (s[i + j] && ft_isconv(s[i + j]))
			j++;
		k = ((j != 0) ? k + 1 : k);
		i = i + j;
	}
	return (k);
}

int				ft_charcount(const char *restrict s, int i, int mode)
{
	int j;

	j = 0;
	if (mode == 1)
	{
		while (s[i + j] && s[i + j] != '%')
			j++;
		return (j);
	}
	else
	{
		if (s[i] && s[i] == '%')
		{
			j++;
			while (s[i + j] && !ft_isconv(s[i + j]))
				j++;
		}
		if (s[i + j] && ft_isconv(s[i + j]))
			j++;
		return (j);
	}
}

char			**ft_formattotab(const char *restrict s)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_partsnbr(s) + 1))))
		return (NULL);
	while (s[i])
	{
		if ((j = ft_charcount(s, i, 1)))
		{
			tab[k] = ft_strsub(s, i, (size_t)j);
			k++;
		}
		else if ((j = ft_charcount(s, i, 2)))
		{
			tab[k] = ft_strsub(s, i, (size_t)j);
			k++;
		}
		i = i + j;
	}
	tab[k] = 0;
	return (tab);
}
