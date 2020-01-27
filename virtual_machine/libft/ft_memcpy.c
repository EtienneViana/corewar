/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:50:39 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:50:42 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*str;
	const char	*str2;

	str = (char*)dst;
	str2 = (const char*)src;
	i = 0;
	while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
	return (dst);
}
