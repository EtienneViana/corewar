/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:03:21 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/14 11:16:00 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_len(int nb, char *base_to, int len)
{
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	if ((size_t)nb > ft_strlen(base_to) - 1)
		return (nbr_len(nb / ft_strlen(base_to), base_to, len + 1));
	else
		return (len + 1);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		len;
	char	*res;
	int		i;

	nb = ft_atoi_base(nbr, base_from);
	len = nbr_len(nb, base_to, 0);
	if (!(res = (char*)malloc(sizeof(char) * (nbr_len(nb, base_to, 0) + 1))))
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		res[i] = '-';
		nb = -nb;
		i++;
	}
	res[len] = '\0';
	while (len > i)
	{
		res[len - 1] = base_to[nb % ft_strlen(base_to)];
		if (nb / ft_strlen(base_to))
			nb = nb / ft_strlen(base_to);
		len--;
	}
	return (res);
}
