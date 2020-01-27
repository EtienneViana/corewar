/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:50:27 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/12 16:52:08 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *str, char *base)
{
	int res;
	int neg;
	int i;

	i = 0;
	neg = 1;
	res = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isbase(str[i], base) < ft_strlen(base))
	{
		res = res * ft_strlen(base) + ft_isbase(str[i], base);
		i++;
	}
	return (neg * res);
}
