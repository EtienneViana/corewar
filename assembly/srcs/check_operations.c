/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:47:49 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/22 14:38:36 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			calc_arg_size(int type, int index)
{
	if (type == T_REG)
		return (1);
	if (type == T_IND)
		return (2);
	if (type == T_DIR)
		return (g_inst[index].t_dir_size);
	return (FAILURE);
}

int			check_type(int type, int i, int index)
{
	if (!(g_inst[index].args_type[i - 1] & type))
		return (FAILURE);
	return (SUCCESS);
}

int			check_arg(char *argument)
{
	if (argument[0] == 'r')
		if (is_reg(argument))
			return (T_REG);
	if (argument[0] == DIRECT_CHAR)
		if (is_dir(argument))
			return (T_DIR);
	if (ft_isdigit(argument[0]) || argument[0] == '-'
		|| argument[0] == LABEL_CHAR)
		if (is_ind(argument))
			return (T_IND);
	return (FAILURE);
}

int			check_arg_type(t_asm *asm_f, t_operation *operation, int index)
{
	int		type;
	size_t	i;

	i = 1;
	operation->size += asm_f->size_tracker;
	asm_f->size_tracker += 1;
	if (g_inst[index].arg_type_code == true)
		asm_f->size_tracker += 1;
	while (i < operation->len)
	{
		if ((type = check_arg(rm_space_around(operation->op[i]))) != 0)
		{
			if (!check_type(type, i, index))
				return (errors(6));
			asm_f->size_tracker += calc_arg_size(type, index);
		}
		else
			return (errors(3));
		i++;
	}
	return (SUCCESS);
}

int			check_operation(t_asm *asm_f, t_operation *operation)
{
	int		i;

	if ((i = is_op(rm_space_around(operation->op[0]))) != -1)
	{
		if (g_inst[i].nb_args != operation->len - 1)
		{
			ft_printf("nb of args is: %lu for %s\n"
			, operation->len - 1, operation->op[0]);
			return (errors(2));
		}
		if (!check_arg_type(asm_f, operation, i))
		{
			print_op(operation);
			return (FAILURE);
		}
	}
	else
	{
		ft_printf("instruction is: %s\n", operation->op[0]);
		return (errors(1));
	}
	return (SUCCESS);
}
