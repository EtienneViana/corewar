/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:25:15 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/22 10:47:12 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		j = i;
		while (base[j])
		{
			if ((base[i] == base[j] && i != j) || base[i] == '-' ||
				base[i] == '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void				ft_putnbr_base(int nbr, char *base)
{
	unsigned int	res;

	res = nbr;
	if (!base || !check_base(base))
		return ;
	if (nbr < 0)
	{
		res = -nbr;
		ft_putchar('-');
	}
	if (res > ft_strlen(base) - 1)
		ft_putnbr_base((res / ft_strlen(base)), base);
	ft_putchar(base[res % ft_strlen(base)]);
}
