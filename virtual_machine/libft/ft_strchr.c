/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:55:38 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:55:41 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	rc;
	char	*str;

	str = (char*)s;
	rc = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == rc)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && rc == 0)
		return (&str[i]);
	return (NULL);
}
