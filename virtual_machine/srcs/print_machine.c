/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_machine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:27:25 by eviana            #+#    #+#             */
/*   Updated: 2020/01/09 18:14:29 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	print_bytes(t_vm *vm, int i)
{
	int color;

	color = vm->owner[i] % 8;
	if (color == 0)
		ft_printf("{eoc}%02x ", vm->mem[i]);
	else if (color == 1)
		ft_printf("{red}%02x ", vm->mem[i]);
	else if (color == 2)
		ft_printf("{green}%02x ", vm->mem[i]);
	else if (color == 3)
		ft_printf("{purple}%02x ", vm->mem[i]);
	else if (color == 4)
		ft_printf("{blue}%02x ", vm->mem[i]);
	else if (color == 5)
		ft_printf("{yellow}%02x ", vm->mem[i]);
	else if (color == 6)
		ft_printf("{cyan}%02x ", vm->mem[i]);
	else if (color == 7)
		ft_printf("{magenta}%02x ", vm->mem[i]);
}

int		get_player_color(t_vm *vm, int players)
{
	int i;

	i = 0;
	while (i < vm->nb_players)
	{
		if (vm->player[i].id == players)
			break ;
		i++;
	}
	if (vm->player[i].id == 1)
		ft_printf("{red}");
	else if (vm->player[i].id == 2)
		ft_printf("{green}");
	else if (vm->player[i].id == 3)
		ft_printf("{purple}");
	else if (vm->player[i].id == 4)
		ft_printf("{blue}");
	return (i);
}

void	print_col_numbers(void)
{
	int i;

	i = 0;
	ft_printf("Col nb : ");
	while (i < 64)
	{
		ft_printf("%02d ", i);
		i++;
	}
	ft_printf("     |\n");
}

int		print_arena(t_vm *vm)
{
	int	i;
	int	lines;
	int	players;

	i = 0;
	players = 0;
	ft_printf("\e[1;1H\e[2J");
	print_col_numbers();
	lines = ft_sqrt(MEM_SIZE);
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % lines == 0)
			print_pannel(vm, i / lines, &players);
		if (i % lines == 0)
			ft_printf("0x%04x : ", i);
		print_bytes(vm, i);
		i++;
	}
	ft_printf("{eoc}     |\n");
	return (0);
}

int		print_dump(t_vm *vm)
{
	int	i;
	int	lines;

	i = 0;
	lines = ft_sqrt(MEM_SIZE);
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % lines == 0)
			ft_printf("\n");
		if (i % lines == 0)
			ft_printf("0x%04x : ", i);
		ft_printf("%02x ", vm->mem[i]);
		i++;
	}
	ft_printf("\n");
	return (0);
}
