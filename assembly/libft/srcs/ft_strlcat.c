/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:21:45 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/08 11:21:47 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	res = ft_strlen(src);
	while (dest[i] && i < size)
		i++;
	j = 0;
	if (size > 0)
	{
		while (src[j] && i < size - 1)
			dest[i++] = src[j++];
	}
	if (j > 0)
	{
		dest[i] = '\0';
		return (res + i - j);
	}
	return (res + i);
}
