/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:36:21 by eviana            #+#    #+#             */
/*   Updated: 2020/01/10 12:45:35 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int		op_ldi(t_vm *vm, t_process *proc)
{
	t_param	params;
	int		offset;

	params = set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[0] == REG_CODE)
			params.n[0] = proc->reg[params.n[0]];
		else if (params.c[0] == IND_CODE)
			params.n[0] = read_address(vm, params.n[0], 4);
		if (params.c[1] == REG_CODE)
			params.n[1] = proc->reg[params.n[1]];
		proc->reg[params.n[2]] = read_address(vm,
			modulo_mem_size(proc->pc + idx_mod(
				params.n[0] + params.n[1])), 4);
	}
	return (offset);
}

int		op_sti(t_vm *vm, t_process *proc)
{
	t_param	params;
	int		offset;

	params = set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[1] == REG_CODE)
			params.n[1] = proc->reg[params.n[1]];
		else if (params.c[1] == IND_CODE)
			params.n[1] = read_address(vm, params.n[1], 4);
		if (params.c[2] == REG_CODE)
			params.n[2] = proc->reg[params.n[2]];
		write_to_address(vm, proc,
			modulo_mem_size(proc->pc + idx_mod(
				params.n[1] + params.n[2])),
			proc->reg[params.n[0]]);
	}
	return (offset);
}

int		op_fork(t_vm *vm, t_process *proc)
{
	t_process *new;

	if (!(new = (t_process*)malloc(sizeof(t_process))))
		return ((vm->malloc_flag = 1));
	new->id = vm->nb_proc++;
	new->master = proc->master;
	new->carry = proc->carry;
	new->last_live = 0;
	new->pc = modulo_mem_size(proc->pc
		+ idx_mod(read_address(vm,
			(proc->pc + 1) % MEM_SIZE, 2)));
	new->current_op = vm->mem[new->pc];
	if (is_valid_op(new->current_op))
		new->cycles_left = g_op_tab[new->current_op - 1].cycles - 1;
	else
		new->cycles_left = 0;
	copy_registers(new, proc);
	new->next = vm->process;
	vm->process = new;
	return (3);
}

int		op_lld(t_vm *vm, t_process *proc)
{
	t_param params;
	int		offset;

	params = set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[0] == IND_CODE)
			params.n[0] = read_address(vm, params.n[0], 4);
		proc->reg[params.n[1]] = params.n[0];
		if (proc->reg[params.n[1]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		op_lldi(t_vm *vm, t_process *proc)
{
	t_param	params;
	int		offset;

	params = set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[0] == REG_CODE)
			params.n[0] = proc->reg[params.n[0]];
		else if (params.c[0] == IND_CODE)
			params.n[0] = read_address(vm, params.n[0], 4);
		if (params.c[1] == IND_CODE)
			params.n[1] = read_address(vm, params.n[1], 4);
		proc->reg[params.n[2]] = read_address(vm,
			modulo_mem_size(proc->pc + params.n[0] + params.n[1]), 4);
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}
