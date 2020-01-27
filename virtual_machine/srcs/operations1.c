/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:41:30 by eviana            #+#    #+#             */
/*   Updated: 2020/01/09 17:41:38 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	set_live_tab(t_vm *vm, int number)
{
	int	y;

	y = 0;
	while (y < 4)
	{
		if (vm->live_tab[y] == -1)
		{
			vm->live_tab[y] = number;
			break ;
		}
		y++;
	}
	if (y == 4)
	{
		ft_memmove(&vm->live_tab[1], vm->live_tab, 3 * sizeof(int));
		vm->live_tab[0] = number;
	}
}

int		op_live(t_vm *vm, t_process *proc)
{
	int	i;
	int	id;

	i = 0;
	id = read_address(vm, (proc->pc + 1) % MEM_SIZE, 4);
	while (i < vm->nb_players)
	{
		if (id == -vm->player[i].id)
		{
			set_live_tab(vm, id * -1);
			vm->player[i].last_live = vm->cycles;
			vm->last_live = &vm->player[i];
		}
		i++;
	}
	proc->last_live = vm->cycles;
	vm->lives_since_check++;
	return (5);
}

int		op_ld(t_vm *vm, t_process *proc)
{
	t_param	params;
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

int		op_st(t_vm *vm, t_process *proc)
{
	t_param	params;
	int		offset;

	params = set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		if (params.c[1] == IND_CODE)
			write_to_address(vm, proc, params.n[1], proc->reg[params.n[0]]);
		else if (params.c[1] == REG_CODE)
			proc->reg[params.n[1]] = proc->reg[params.n[0]];
	}
	return (offset);
}

int		op_add(t_vm *vm, t_process *proc)
{
	t_param params;
	int		offset;

	params = set_params(vm, proc, proc->pc, &offset);
	if (params.valid)
	{
		proc->reg[params.n[2]] = proc->reg[params.n[0]]
			+ proc->reg[params.n[1]];
		if (proc->reg[params.n[2]] == 0)
			proc->carry = 1;
		else
			proc->carry = 0;
	}
	return (offset);
}
