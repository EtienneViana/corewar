/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:00:42 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 19:00:43 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s || !(str = ft_strnew(n)))
		return (NULL);
	while (i < n)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
