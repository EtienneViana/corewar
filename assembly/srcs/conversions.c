/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:38:53 by yabecret          #+#    #+#             */
/*   Updated: 2020/01/07 16:05:44 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char				*get_bits(const unsigned long v)
{
	size_t			size;
	unsigned long	remainder;
	char			*ret;
	int				i;

	remainder = 0;
	i = 0;
	size = 32;
	if (!(ret = (char*)ft_memalloc(sizeof(char) * 32 + 1)))
		return (NULL);
	while (size--)
	{
		if ((remainder = v >> size))
		{
			ret[i] = (remainder & 1) ? '1' : '0';
			i++;
		}
	}
	ret[i] = '\0';
	return (ret);
}

unsigned int		conv_binary_to_dec(char *b)
{
	unsigned int	dec_nb;
	unsigned int	remainder;
	int				i;
	int				j;

	dec_nb = 0;
	i = 0;
	j = ft_strlen(b);
	while (j > 0)
	{
		remainder = b[j - 1] - 48;
		dec_nb += remainder * ft_pow(2, i);
		j--;
		++i;
	}
	ft_strdel(&b);
	return (dec_nb);
}

/*
**	ft_printf("conv_dec value : %ld\n", value);
**	ft_printf("b is %s\n", b);
**	ft_printf("ret : %d\n", ret);
*/

unsigned int		conv_decimal(long value)
{
	char			*b;
	unsigned int	ret;

	b = get_bits(value);
	ret = conv_binary_to_dec(b);
	return (ret);
}
