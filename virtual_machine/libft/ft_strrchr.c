/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:00:06 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 19:00:07 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	rc;
	char	*str;

	str = (char*)s;
	rc = (char)c;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != rc && i != 0)
		i--;
	if (str[i] == rc)
		return (&str[i]);
	else
		return (NULL);
}
