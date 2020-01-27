/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_review.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:47:30 by anrzepec          #+#    #+#             */
/*   Updated: 2020/01/08 20:04:06 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int		op_dispatch(t_vm *vm, t_process *proc, int op_code)
{
	int (*op[16])(t_vm *, t_process *);

	op[0] = &op_live;
	op[1] = &op_ld;
	op[2] = &op_st;
	op[3] = &op_add;
	op[4] = &op_sub;
	op[5] = &op_and;
	op[6] = &op_or;
	op[7] = &op_xor;
	op[8] = &op_zjmp;
	op[9] = &op_ldi;
	op[10] = &op_sti;
	op[11] = &op_fork;
	op[12] = &op_lld;
	op[13] = &op_lldi;
	op[14] = &op_lfork;
	op[15] = &op_aff;
	return (op[op_code - 1](vm, proc));
}

void	get_cycles_left(t_process *proc)
{
	if (is_valid_op(proc->current_op))
		proc->cycles_left = g_op_tab[proc->current_op - 1].cycles - 1;
	else
		proc->cycles_left = 0;
}

void	set_current_op(t_vm *vm, t_process *proc)
{
	proc->current_op = vm->mem[proc->pc];
	get_cycles_left(proc);
}

int		update_process(t_vm *vm, t_process *proc)
{
	int offset;

	if (proc->current_op != vm->mem[proc->pc])
		set_current_op(vm, proc);
	else if (!is_valid_op(proc->current_op))
	{
		proc->pc = (proc->pc + 1) % MEM_SIZE;
		set_current_op(vm, proc);
	}
	else
	{
		offset = op_dispatch(vm, proc, proc->current_op);
		proc->pc = modulo_mem_size(proc->pc + offset);
		set_current_op(vm, proc);
	}
	return (vm->malloc_flag ? ALLOC_ERROR : 0);
}

int		process_review(t_vm *vm, t_process *process)
{
	if (!process->cycles_left || process->current_op != vm->mem[process->pc])
	{
		if (update_process(vm, process))
			return (ALLOC_ERROR);
	}
	else
		process->cycles_left--;
	return (0);
}
