/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:45:44 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:45:46 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nearsqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i <= nb && i <= 46340)
		i++;
	return (i);
}

int			ft_is_prime(int nb)
{
	int i;
	int nearsqrt;

	i = 2;
	nearsqrt = ft_nearsqrt(nb);
	if (nb <= 1)
		return (0);
	while (i < nearsqrt)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
