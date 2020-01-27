/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:03:35 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/12 16:03:40 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *tmp;

	tmp = dest;
	while (n--)
	{
		if ((*tmp++ = *(unsigned char*)src++) == c)
		{
			dest = tmp;
			return (dest);
		}
	}
	return (NULL);
}
