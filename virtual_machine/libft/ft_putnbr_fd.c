/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:53:08 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 18:53:10 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int newnb;

	newnb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		newnb = -newnb;
	}
	if (newnb >= 10)
		ft_putnbr_fd((newnb / 10), fd);
	ft_putchar_fd((newnb % 10) + '0', fd);
}
