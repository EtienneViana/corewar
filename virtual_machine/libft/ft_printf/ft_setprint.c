/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:14:37 by eviana            #+#    #+#             */
/*   Updated: 2019/03/09 16:24:16 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	**ft_setprint(char **tab)
{
	char	**print;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if (!(print = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	print[i] = 0;
	return (print);
}
