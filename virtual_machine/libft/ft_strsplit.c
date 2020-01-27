/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:00:15 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 19:00:18 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			**tab;

	i = 0;
	k = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_strcount(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (j != 0)
		{
			tab[k] = ft_strsub(s, i, (size_t)j);
			k++;
		}
		i = i + j;
	}
	tab[k] = 0;
	return (tab);
}
