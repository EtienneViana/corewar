/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:08:26 by anrzepec          #+#    #+#             */
/*   Updated: 2020/01/08 14:08:29 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

t_process		*load_process_from_player(t_player player)
{
	t_process *process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (NULL);
	process->master = player.id;
	process->carry = 0;
	process->last_live = 0;
	process->current_op = player.exec[0];
	process->cycles_left = g_op_tab[process->current_op - 1].cycles - 1;
	init_registers(process);
	process->next = NULL;
	return (process);
}

void			find_process_position(t_process **lst, t_process *proc)
{
	t_process	*tracer;
	t_process	*tmp;

	tracer = *lst;
	tmp = NULL;
	while (tracer && tracer->master > proc->master)
	{
		tmp = tracer;
		tracer = tracer->next;
	}
	if (!tmp)
	{
		proc->next = *lst;
		*lst = proc;
	}
	else
	{
		proc->next = tracer;
		tmp->next = proc;
	}
}

void			place_process(t_process **lst, t_process *proc, int i)
{
	proc->id = i;
	if (!*lst)
		*lst = proc;
	else if (!(*lst)->next)
	{
		if ((*lst)->master < proc->master)
		{
			proc->next = *lst;
			*lst = proc;
		}
		else
			(*lst)->next = proc;
	}
	else
		find_process_position(lst, proc);
}

int				load_process_list(t_vm *vm)
{
	int			i;
	t_process	*proc;

	i = 0;
	while (i < vm->nb_players)
	{
		if (!(proc = load_process_from_player(vm->player[i])))
			return (ALLOC_ERROR);
		place_process(&(vm->process), proc, i);
		i++;
	}
	vm->nb_proc = vm->nb_players;
	return (0);
}
