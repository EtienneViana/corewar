/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:58:15 by eviana            #+#    #+#             */
/*   Updated: 2019/11/15 16:57:30 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

t_process		*list_pop(t_vm *vm)
{
	t_process *first;

	first = vm->process;
	vm->process = vm->process->next;
	free(first);
	return (vm->process);
}

t_process		*list_delone(t_process *prec, t_process *current)
{
	prec->next = current->next;
	free(current);
	return (prec->next);
}

int				process_life_check(t_vm *vm)
{
	t_process *tracer;
	t_process *prec;

	prec = vm->process;
	tracer = vm->process;
	while (tracer)
	{
		if (tracer->last_live <= vm->last_verif)
		{
			if (tracer == vm->process)
				tracer = list_pop(vm);
			else
				tracer = list_delone(prec, tracer);
		}
		else
		{
			prec = tracer;
			tracer = tracer->next;
		}
	}
	return (0);
}

int				life_check(t_vm *vm)
{
	process_life_check(vm);
	if (vm->process == NULL && vm->last_live)
	{
		ft_printf("The winner is: %20s (%d)\n",
			vm->last_live->name, vm->last_live->id);
		return (END_GAME);
	}
	return (0);
}
