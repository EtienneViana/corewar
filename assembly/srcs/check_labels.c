/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:26:31 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/09 17:14:29 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	ft_printf("token label is {green}|%s|{reset}\n", list->name);
**	ft_printf("label in inst is {yellow}|%s|{reset}\n", label);
**	ft_printf("{blue}token size is %d{reset}\n", token->size);
**	ft_printf("{blue}label size is %d{reset}\n", tmp->size);
*/

int				find_label(t_token *token, char *label)
{
	t_token		*tmp;
	t_label		*list;

	tmp = token;
	while (tmp)
	{
		list = tmp->label;
		while (list)
		{
			if (ft_strcmp(list->name, label) == 0)
				return (tmp->size);
			list = list->next;
		}
		tmp = tmp->next;
	}
	return (-1);
}

int				check_instr_label_in_op(t_asm *asm_f, t_operation *operation)
{
	char		*label;
	size_t		i;
	size_t		j;

	while (operation)
	{
		i = 1;
		while (i < operation->len)
		{
			if (is_label_instr(operation->op[i]))
			{
				j = 0;
				label = operation->op[i];
				j = (operation->op[i][j] == '%') ? j + 2 : j + 1;
				label = label + j;
				if (find_label(asm_f->first_tk, label) == -1)
					return (FAILURE);
			}
			++i;
		}
		operation = operation->next;
	}
	return (SUCCESS);
}

int				check_instr_label_in_tk(t_asm *asm_f, t_token *token)
{
	t_token		*tmp;
	t_operation *token_op;

	if (!token)
		return (FAILURE);
	tmp = token;
	while (tmp)
	{
		token_op = tmp->operation;
		if (!check_instr_label_in_op(asm_f, token_op))
			return (FAILURE);
		tmp = tmp->next;
	}
	return (SUCCESS);
}
