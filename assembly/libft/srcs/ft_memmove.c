/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:06:56 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/12 16:06:58 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *tmp;

	tmp = dest;
	if (src > dest)
		dest = ft_memcpy(tmp, src, n);
	if (src < dest)
	{
		src = src + (n - 1);
		tmp = tmp + (n - 1);
		while (n--)
			*tmp-- = *(unsigned char*)src--;
	}
	return (dest);
}
