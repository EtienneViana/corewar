/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:44:20 by anrzepec          #+#    #+#             */
/*   Updated: 2019/10/18 14:11:53 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnum(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (ft_isdigit(s[i]))
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
