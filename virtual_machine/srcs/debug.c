/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:58:52 by eviana            #+#    #+#             */
/*   Updated: 2020/01/09 17:58:57 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	debug_lines(t_vm *vm)
{
	int			i;
	t_process	*current;

	current = vm->process;
	ft_printf("\nDEBUG :\n");
	while (current)
	{
		i = 0;
		ft_printf("Proc %d(m%d) pc : %d | c_op : %d | c",
			current->id, current->master,
			current->pc, current->current_op);
		ft_printf("_left : %d | last_l : %d | regs : [",
			current->cycles_left, current->last_live);
		while (++i < 17)
			ft_printf("%d : %d | ", i, current->reg[i]);
		ft_printf("]\n");
		current = current->next;
	}
}
