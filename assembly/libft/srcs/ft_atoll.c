/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:04:41 by yabecret          #+#    #+#             */
/*   Updated: 2019/10/23 00:33:45 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoll(char *s)
{
	intmax_t	res;
	intmax_t	nega;
	int			i;

	i = 0;
	nega = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			nega = -1;
	}
	res = 0;
	while (s[i] && ft_isdigit(s[i]))
	{
		res += s[i] - 48;
		if (ft_isdigit(s[i + 1]))
			res *= 10;
		i++;
	}
	return (res * nega);
}
