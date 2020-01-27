/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:00:08 by mjouffro          #+#    #+#             */
/*   Updated: 2019/11/22 14:21:00 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token			*init_token(int index)
{
	t_token		*token;

	if (!(token = ft_memalloc(sizeof(t_token))))
	{
		errors(5);
		return (FAILURE);
	}
	token->pos = 0;
	token->next = NULL;
	token->id = index;
	return (token);
}

t_label			*create_label(char *line, int len)
{
	t_label		*label;

	if (!(label = ft_memalloc(sizeof(t_token))))
	{
		errors(5);
		return (FAILURE);
	}
	label->name = ft_strsub(line, 0, len - 1);
	label->pos = 0;
	label->next = NULL;
	return (label);
}

t_operation		*memalloc_op(void)
{
	t_operation	*operation;

	if ((operation = (t_operation*)ft_memalloc(sizeof(t_operation))) == NULL)
	{
		errors(5);
		return (FAILURE);
	}
	operation->len = 0;
	operation->next = NULL;
	return (operation);
}
