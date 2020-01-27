/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:01:24 by plaurent          #+#    #+#             */
/*   Updated: 2019/05/29 19:01:25 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_countsize(unsigned long long n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_ulltoa(unsigned long long n)
{
	unsigned long long	newnb;
	int					i;
	char				*str;

	newnb = n;
	i = st_countsize(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (newnb != 0)
	{
		str[i - 1] = (newnb % 10) + '0';
		newnb = newnb / 10;
		i--;
	}
	return (str);
}
