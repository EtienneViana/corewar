/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:56:16 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/14 11:21:08 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	if (!(new = ft_strnew(ft_cntdigit(n))))
		return (NULL);
	if (n == 0 || n == -2147483648)
		return (n == 0 ? ft_strdup("0") : ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		new[i++] = '-';
	}
	while (n / j)
		j *= 10;
	j /= 10;
	while (j > 0)
	{
		new[i++] = (n / j % 10 + 48);
		j /= 10;
	}
	new[i] = '\0';
	return (new);
}
