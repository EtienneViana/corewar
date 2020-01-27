/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:40:12 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/09 21:16:39 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				free_operation_lst(t_operation *operation)
{
	t_operation *next;
	size_t		i;

	if (!operation)
		return (FAILURE);
	while (operation)
	{
		next = operation->next;
		free(operation->value);
		if (operation->op)
		{
			i = 0;
			while (i < operation->len)
				ft_strdel(&operation->op[i++]);
			free(operation->op);
		}
		free(operation);
		operation = next;
	}
	return (SUCCESS);
}

int				free_label_lst(t_label *label)
{
	t_label		*next;

	if (!label)
		return (FAILURE);
	while (label)
	{
		next = label->next;
		if (label->name)
			ft_strdel(&label->name);
		free(label);
		label = next;
	}
	return (SUCCESS);
}

int				free_token(t_token *token)
{
	if (token->label)
		free_label_lst(token->label);
	if (token->operation)
		free_operation_lst(token->operation);
	free(token);
	return (SUCCESS);
}

int				free_token_lst(t_token *token)
{
	t_token		*next;

	if (!token)
		return (FAILURE);
	while (token)
	{
		next = token->next;
		free_token(token);
		token = next;
	}
	return (SUCCESS);
}

int				free_asm_and_token(t_asm *asm_f)
{
	if (!asm_f)
		return (FAILURE);
	if (asm_f->origin)
		ft_strdel(&asm_f->origin);
	if (asm_f->file)
		ft_strdel(&asm_f->file);
	if (asm_f->name)
		ft_strdel(&asm_f->name);
	if (asm_f->comment)
		ft_strdel(&asm_f->comment);
	if (asm_f->first_tk)
		free_token_lst(asm_f->first_tk);
	return (SUCCESS);
}
