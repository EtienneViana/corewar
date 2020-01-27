/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_asset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:36:55 by plaurent          #+#    #+#             */
/*   Updated: 2019/02/14 14:37:27 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printasset(t_asset asset)
{
	ft_putstr("flags : ");
	ft_putstr(asset.flags);
	ft_putchar('\n');
	ft_putstr("width : ");
	ft_putnbr(asset.width);
	ft_putchar('\n');
	ft_putstr("precision : ");
	ft_putnbr(asset.precision);
	ft_putchar('\n');
	ft_putstr("length : ");
	ft_putnbr(asset.length);
	ft_putchar('\n');
	ft_putstr("type : ");
	ft_putnbr(asset.type);
	ft_putchar('\n');
}
