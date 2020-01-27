/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:33:09 by eviana            #+#    #+#             */
/*   Updated: 2020/01/10 12:46:16 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int		get_param(t_vm *vm, t_process *proc, int pc, int code)
{
	int dir_size;

	dir_size = (g_op_tab[proc->current_op - 1].dir_size ? 2 : 4);
	if (code == REG_CODE)
	{
		if (is_valid_reg(read_address(vm, pc, 1)))
			return (read_address(vm, pc, 1));
		else
			return (-1);
	}
	else if (code == DIR_CODE)
		return (read_address(vm, pc, dir_size));
	else if (code == IND_CODE)
	{
		if (g_op_tab[proc->current_op - 1].restr)
			return (modulo_mem_size(
					proc->pc + idx_mod(read_address(vm, pc, 2))));
		else
			return ((proc->pc + read_address(vm, pc, 2)) % MEM_SIZE);
	}
	return (0);
}

int		param_size(int code, int dir_size)
{
	if (code == REG_CODE)
		return (1);
	else if (code == DIR_CODE)
		return (dir_size);
	else if (code == IND_CODE)
		return (2);
	return (0);
}

t_param	set_params(t_vm *vm, t_process *proc, int pc, int *offset)
{
	int		i;
	char	ocp;
	t_param	params;
	int		dir_size;

	i = 0;
	ocp = vm->mem[(pc + 1) % MEM_SIZE];
	pc = (pc + 2) % MEM_SIZE;
	*offset = 2;
	params.valid = 1;
	if (!check_ocp(proc, ocp))
		params.valid = 0;
	dir_size = (g_op_tab[proc->current_op - 1].dir_size ? 2 : 4);
	while (i < 3)
	{
		params.c[i] = get_code(ocp >> (6 - (2 * i)));
		if ((params.n[i] = get_param(vm, proc, pc, params.c[i])) == -1)
			params.valid = 0;
		pc = (pc + param_size(params.c[i], dir_size)) % MEM_SIZE;
		*offset = *offset + param_size(params.c[i], dir_size);
		i++;
	}
	return (params);
}
