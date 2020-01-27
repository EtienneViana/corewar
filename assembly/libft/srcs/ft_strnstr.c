/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:23:15 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/08 11:23:17 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;

	i = 0;
	if (!*big)
	{
		if (*big == *little)
			return ((char*)big);
		else
			return (NULL);
	}
	while (*big)
	{
		if (ft_strnequ(little, big, ft_strlen(little)))
			if (ft_strlen(little) + i <= len)
				return ((char*)big);
		i++;
		big++;
	}
	return (NULL);
}
