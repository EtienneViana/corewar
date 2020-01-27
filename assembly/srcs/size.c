/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:06:14 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/07 14:06:47 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					total_size(t_token *token)
{
	t_token			*tmp;
	int				size;

	size = 0;
	tmp = token;
	while (tmp)
	{
		size += tmp->size;
		tmp = tmp->next;
	}
	return (size);
}

void				fill_value2(t_asm *asm_file, t_operation *operation, int i)
{
	char			*label;

	if (operation->op[i - 1][0] == '%' && operation->op[i - 1][1] != ':')
		operation->value[i] = conv_decimal(ft_atoi(&operation->op[i - 1][1]));
	else if (is_label_instr(operation->op[i - 1]))
	{
		label = operation->op[i - 1] + 2;
		operation->value[i] = conv_decimal((
			find_label(asm_file->first_tk, label) - operation->size));
	}
}

void				fill_value4(t_asm *asm_file, t_operation *operation, int i)
{
	char			*label;

	if (operation->op[i - 1][0] == ':')
	{
		label = operation->op[i - 1] + 1;
		operation->value[i] = conv_decimal((
			find_label(asm_file->first_tk, label) - operation->size));
	}
	else
		operation->value[i] = conv_decimal(ft_atoi(operation->op[i - 1]));
}

int					fill_arg_value(t_asm *asm_file, t_operation *operation)
{
	size_t			i;

	i = 2;
	while (i <= operation->len)
	{
		if (operation->value[i] == 1)
			operation->value[i] = ft_atoi(operation->op[i - 1] + 1);
		else if (operation->value[i] == 2)
			fill_value2(asm_file, operation, i);
		else if (operation->value[i] == 4)
			fill_value4(asm_file, operation, i);
		i++;
	}
	return (SUCCESS);
}

int					fill_value_tab(t_asm *asm_file, t_token *token)
{
	t_token			*tmp;
	t_operation		*lst;
	size_t			j;

	tmp = token;
	while (tmp)
	{
		lst = tmp->operation;
		while (lst)
		{
			if (!(lst->value = (int*)ft_memalloc(sizeof(int) * 5)))
				return (errors(5));
			lst->value[0] = is_op(lst->op[0]) + 1;
			if (g_inst[lst->value[0] - 1].arg_type_code == true)
				lst->value[1] = get_arg_type_code(lst);
			j = 1;
			while (++j < lst->len + 1)
				lst->value[j] = check_arg(lst->op[j - 1]);
			fill_arg_value(asm_file, lst);
			lst = lst->next;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}
