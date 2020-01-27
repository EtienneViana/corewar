/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:23:30 by yabecret          #+#    #+#             */
/*   Updated: 2020/01/14 17:29:04 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_newlen(char *s, char c)
{
	size_t n;

	while (*s && *s == c)
		s++;
	n = (*s ? 1 : 0);
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			n++;
		s++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	n;
	char	*tmp;
	char	**new;

	if (!s)
		return (NULL);
	n = ft_newlen((char*)s, c);
	if (!(new = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	tmp = (char*)s;
	while (*s)
	{
		if (*s == c)
		{
			if (tmp != s)
				*(new++) = ft_strsub(tmp, 0, s - tmp);
			tmp = (char*)s + 1;
		}
		s++;
	}
	if (tmp != s)
		*(new++) = ft_strsub(tmp, 0, s - tmp);
	*new = NULL;
	return (new - n);
}
