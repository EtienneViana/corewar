/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:38:54 by yabecret          #+#    #+#             */
/*   Updated: 2018/11/20 15:38:23 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isop(char c)
{
	if (c == 43 || c == 45 || c == '\n')
		return (1);
	return (0);
}

char		*ft_strcapitalize(char *str)
{
	int i;

	if (ft_islower(str[0]) && ft_isalpha(str[1]))
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
		{
			if (ft_islower(str[i]) && (ft_isblank(str[i - 1]) ||
				ft_isop(str[i - 1])))
				str[i] -= 32;
			else if (ft_isupper(str[i]) && (!(ft_isblank(str[i - 1]) ||
					ft_isop(str[i - 1]))))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
