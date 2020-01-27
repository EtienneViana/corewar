/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_virtual_machine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:44:35 by andrewrze         #+#    #+#             */
/*   Updated: 2020/01/09 11:47:32 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	cycle_review(t_vm *vm)
{
	if (++(vm->nb_checks) == MAX_CHECKS || vm->lives_since_check >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->nb_checks = 0;
		vm->cycles_to_die = vm->cycles_to_die < 1 ? 1 : vm->cycles_to_die;
	}
	vm->last_verif = vm->cycles;
	vm->lives_since_check = 0;
}

int		option_review(t_vm *vm)
{
	if (vm->dump == vm->cycles)
	{
		print_dump(vm);
		return (END_GAME);
	}
	if (vm->vis != -1 && !(vm->cycles % vm->vis))
	{
		print_arena(vm);
		sleep(1);
	}
	return (0);
}

int		machine_review(t_vm *vm)
{
	if (option_review(vm))
		return (END_GAME);
	if (vm->cycles && !((vm->cycles - vm->last_verif) % vm->cycles_to_die))
	{
		if (life_check(vm))
			return (END_GAME);
		cycle_review(vm);
	}
	return (0);
}

void	introduce_players(t_vm *vm)
{
	int			i;
	t_process	*tracer;

	tracer = vm->process;
	ft_printf("Introducing the champions up for battle...\n");
	while (tracer)
	{
		i = -1;
		while (++i < vm->nb_players)
			if (vm->player[i].id == tracer->master)
				break ;
		ft_printf("%s (%d), weighing in at %d bytes, \"%s\"\n",
			vm->player[i].name, tracer->master, vm->player[i].size,
			vm->player[i].comment);
		tracer = tracer->next;
	}
	ft_printf("{red}\nLEEEEEEEEET'S GEEEET");
	ft_printf(" REAAAADDDDYY TOOO RUUUUUUMBLEEEEEE!{eoc}\n\n");
}

int		exec_machine(t_vm *vm)
{
	t_process *champion;

	introduce_players(vm);
	while (machine_review(vm) != END_GAME)
	{
		champion = vm->process;
		while (champion)
		{
			if (process_review(vm, champion))
				return (ALLOC_ERROR);
			champion = champion->next;
		}
		vm->cycles++;
	}
	return (END_GAME);
}
