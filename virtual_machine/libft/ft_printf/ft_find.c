/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:49:55 by eviana            #+#    #+#             */
/*   Updated: 2019/03/19 14:02:10 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_findflags(char *tab)
{
	char	*tmp;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = ft_strnew(0);
	tmp = ft_strnew(1);
	while (tab[++i])
	{
		if (tab[i] == '-' || tab[i] == '+' || tab[i] == ' ' || tab[i] == '#')
		{
			tmp[0] = tab[i];
			if (!(str = sp_strnjoin(str, tmp, 1, 0)))
				return (NULL);
		}
		if (tab[i] == '0' && (tab[i - 1] < '0' || tab[i - 1] > '9') &&
				tab[i - 1] != '.')
			if (!(str = sp_strnjoin(str, ft_strsub(tab, i, 1), 1, 2)))
				return (NULL);
	}
	free(tmp);
	return (str);
}

size_t	ft_findwidth(char *tab)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	n = 0;
	while (tab[++i])
		if (tab[i] <= '9' && tab[i] > '0')
		{
			j = 1;
			while (tab[i - j] == '0')
				j++;
			if (tab[i - j] != '.' && (tab[i - j] < '0' || tab[i - j] > '9'))
			{
				n = 0;
				while (tab[i] <= '9' && tab[i] >= '0')
					n = 10 * n + (tab[i++] - '0');
			}
		}
	return (n);
}

int		ft_findprecision(char *tab)
{
	size_t	i;
	int		n;

	i = 0;
	n = -1;
	while (tab[++i])
		if (tab[i] == '.')
		{
			n = 0;
			while (tab[i + 1] && tab[i + 1] >= '0' && tab[i + 1] <= '9')
				n = 10 * n + (tab[i++ + 1] - '0');
		}
	return (n);
}

int		ft_findlength(char *tab)
{
	size_t i;

	i = 0;
	while (tab[++i])
	{
		if (tab[i] && tab[i] == 'l')
			return ((tab[i + 1] && tab[i + 1] == 'l' ? 2 : 1));
		else if (tab[i] && tab[i] == 'h')
			return ((tab[i + 1] && tab[i + 1] == 'h' ? 4 : 3));
		else if (tab[i] && tab[i] == 'L' && ft_strchr(tab, 'f'))
			return (5);
	}
	return (0);
}

int		ft_findtype(char *tab)
{
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	if (!tab)
		ft_putchar('a');
	if (tab[i] == '%')
	{
		while (tab[i])
			i++;
		i--;
		(tab[i] == 'd' || tab[i] == 'i' ? n = 1 : 0);
		(tab[i] == 'o' ? n = 21 : 0);
		(tab[i] == 'u' ? n = 22 : 0);
		(tab[i] == 'x' ? n = 23 : 0);
		(tab[i] == 'X' ? n = 24 : 0);
		(tab[i] == 'c' ? n = 3 : 0);
		(tab[i] == 's' ? n = 4 : 0);
		(tab[i] == 'p' ? n = 5 : 0);
		(tab[i] == 'f' ? n = 6 : 0);
		(tab[i] == '%' && i != 0 ? n = 7 : 0);
	}
	return (n);
}
