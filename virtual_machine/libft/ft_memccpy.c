/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:50:27 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:50:28 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned const char	*str2;

	i = 0;
	str = (unsigned char*)dst;
	str2 = (unsigned const char*)src;
	while (i < n)
	{
		str[i] = str2[i];
		if (str2[i] == (unsigned char)c)
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}
