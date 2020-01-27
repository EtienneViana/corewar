/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:24:58 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/14 10:41:12 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(unsigned int nbr)
{
	char			*base;
	unsigned int	res;

	base = "0123456789ABCDEF";
	res = nbr;
	if (res > 16 - 1)
		ft_puthexa(res / 16);
	ft_putchar(base[res % 16]);
}
