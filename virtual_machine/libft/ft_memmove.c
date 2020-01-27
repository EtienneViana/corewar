/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:51:25 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:51:26 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*str;
	const char	*str2;

	str = (char*)dst;
	str2 = (const char*)src;
	if (dst < src)
		ft_memcpy(dst, src, n);
	else if (dst > src)
	{
		while (n != 0)
		{
			str[n - 1] = str2[n - 1];
			n--;
		}
	}
	return (dst);
}
