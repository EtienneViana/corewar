/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:00:53 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 19:00:54 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	size_t			n;
	char			*str;

	i = 0;
	j = 1;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[n - j] == ' ' || s[n - j] == '\n' || s[n - j] == '\t')
		j++;
	str = ft_strsub(s, i, (size_t)(n - i - j + 1));
	return (str);
}
