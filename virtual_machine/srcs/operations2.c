/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:35:53 by eviana            #+#    #+#             */
/*   Updated: 2020/01/10 12:44:11 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int		op_sub(t_vm *vm, t_process *proc)
{
	t_param params;
	int		offset;

	params = set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		proc->reg[params.n[2]] = proc->reg[params.n[0]]
			- proc->reg[params.n[1]];
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		op_and(t_vm *vm, t_process *proc)
{
	t_param params;
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
		else if (params.c[1] == IND_CODE)
			params.n[1] = read_address(vm, params.n[1], 4);
		proc->reg[params.n[2]] = params.n[0] & params.n[1];
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		op_or(t_vm *vm, t_process *proc)
{
	t_param params;
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
		else if (params.c[1] == IND_CODE)
			params.n[1] = read_address(vm, params.n[1], 4);
		proc->reg[params.n[2]] = params.n[0] | params.n[1];
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		op_xor(t_vm *vm, t_process *proc)
{
	t_param params;
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
		else if (params.c[1] == IND_CODE)
			params.n[1] = read_address(vm, params.n[1], 4);
		proc->reg[params.n[2]] = params.n[0] ^ params.n[1];
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}

int		op_zjmp(t_vm *vm, t_process *proc)
{
	if (proc->carry)
		return (
			idx_mod(read_address(vm, (proc->pc + 1) % MEM_SIZE, 2)));
	else
		return (3);
}
