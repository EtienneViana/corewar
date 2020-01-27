/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:52:55 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:52:56 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int newnb;

	newnb = n;
	if (n < 0)
	{
		ft_putchar('-');
		newnb = -newnb;
	}
	if (newnb >= 10)
		ft_putnbr(newnb / 10);
	ft_putchar((newnb % 10) + '0');
}
