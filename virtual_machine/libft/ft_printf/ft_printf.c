/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/03/19 14:23:49 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	st_tabdel(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	char	**tab;
	int		print_length;

	if (!format)
		return (-1);
	va_start(ap, format);
	tab = ft_formattotab(format);
	if ((print_length = ft_pre_dispatch(tab, ap)) == -1)
	{
		va_end(ap);
		return (-1);
	}
	if (tab)
		st_tabdel(tab);
	va_end(ap);
	ft_fill_buff("", 2);
	return (print_length);
}
