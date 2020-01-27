/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pannel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:13:27 by eviana            #+#    #+#             */
/*   Updated: 2020/01/09 18:14:03 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	pannel_line(char *line)
{
	char	pannel[60];

	ft_bzero(pannel, 60);
	ft_printf(ft_strcat(ft_strcpy(pannel, "          "), line));
}

void	print_war(int line)
{
	if (line == 2)
		ft_printf(
			"                   />");
	else if (line == 3)
		ft_printf(
			"      ()          //---------------------------(");
	else if (line == 4)
		ft_printf(
			"     (*)OXOXOXOXO(*>        --COREWAR--         {red}\\{eoc}");
	else if (line == 5)
		ft_printf(
			"      ()          \\\\-----------{red}------------------){eoc}");
	else if (line == 6)
		ft_printf(
			"                   \\>                          {red}  \"{eoc}");
	else if (line == 7)
		ft_printf(
			"                                                 {red}'{eoc}");
}

void	print_pannel3(t_vm *vm, int line)
{
	if (line == 24)
	{
		ft_printf("        %-25s {yellow}%d{eoc}", "  Lives since check:",
		vm->lives_since_check);
	}
	if (line == 18)
		ft_printf("        %-25s %d", "  Number of players:", vm->nb_players);
	if (line == 20)
		ft_printf("        %-25s %d", "  Number of processes:", vm->nb_proc);
	if (line == 22)
		ft_printf("        %-25s %d", "  Last check: ", vm->last_verif);
}

void	print_pannel2(t_vm *vm, int line, int *players)
{
	int i;

	if (line == 9 || line == 15 || line == 27 || line == 32)
	{
		ft_printf("---------------------------------");
		ft_printf("--------------------------------");
	}
	else if (line == 28 + (*players) && *players < 4)
	{
		if (vm->live_tab[*players] != -1)
		{
			i = get_player_color(vm, vm->live_tab[*players]);
			ft_printf("          %s (%d) has called Live!{eoc}",
				vm->player[i].name, vm->player[i].id);
		}
		(*players)++;
	}
	print_pannel3(vm, line);
}

void	print_pannel(t_vm *vm, int line, int *players)
{
	ft_printf("{eoc}     |");
	if (line < 8)
		print_war(line);
	else if (line == 11)
	{
		pannel_line("current cycle : ");
		ft_printf("%d", vm->cycles);
	}
	else if (line == 12)
	{
		pannel_line("last alive : ");
		ft_printf("%s (%d)", vm->last_live->name, vm->last_live->id);
	}
	else if (line == 13)
	{
		pannel_line("cycles to die : ");
		ft_printf("%d", vm->cycles_to_die);
	}
	print_pannel2(vm, line, players);
	ft_printf("\n");
}
