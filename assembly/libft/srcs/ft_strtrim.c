/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:23:51 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/09 15:14:01 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*new;
	size_t		i;
	size_t		j;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_iswhitespace(s[i]))
		i++;
	if (!(s[i]))
		return (ft_strnew(1));
	j = (ft_strlen(s) - 1);
	while (ft_iswhitespace(s[j]))
		j--;
	j = j - i + 1;
	new = ft_strsub(s, i, j);
	return (new);
}
