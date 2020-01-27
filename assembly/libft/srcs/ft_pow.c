/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 11:48:40 by yabecret          #+#    #+#             */
/*   Updated: 2019/04/24 12:00:49 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double nb, int pow)
{
	double	tmp;

	if (pow == 0)
		return (1);
	tmp = ft_pow(nb, pow / 2);
	if ((pow % 2) == 0)
		return (tmp * tmp);
	else
	{
		if (pow > 0)
			return (nb * tmp * tmp);
		else
			return ((tmp * tmp) / nb);
	}
}
