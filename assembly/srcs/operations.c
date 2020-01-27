/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:47:44 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/20 20:21:15 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static size_t	token_len(char *s)
{
	size_t		n;

	while (*s && *s == ' ')
		s++;
	n = (*s ? 1 : 0);
	while (*s && n < 2)
	{
		if ((*s == ' ' && (*(s + 1) != ' ' || *(s + 1) != '\t'))
		|| (*s == '\t' && (*(s + 1) != '\t' || *(s + 1) != ' ')))
			n++;
		if (n == 1 && *s == '%')
			n++;
		s++;
	}
	while (*s)
	{
		if (*s == SEPARATOR_CHAR)
			n++;
		if (n == 1 && *s == '%')
			n++;
		s++;
	}
	return (n);
}

char			**op_token(char *s, char *tmp, size_t nb_args, int cnt)
{
	char		**new;

	if (!(new = (char**)ft_memalloc(sizeof(char*) * (nb_args))))
		return (NULL);
	while (*s && s++)
	{
		if (valid_op_separator(s, cnt))
		{
			if (tmp != s)
			{
				tmp = ft_strsub(tmp, 0, s - tmp);
				*(new++) = ft_strtrim(tmp);
				free(tmp);
				cnt++;
			}
			tmp = (cnt == 1 && *s == '%') ? s : s + 1;
		}
	}
	if (tmp != s)
	{
		tmp = ft_strsub(tmp, 0, s - tmp);
		*(new++) = ft_strtrim(tmp);
		free(tmp);
	}
	return (new - nb_args);
}

void			add_op(t_operation **op, t_operation *new)
{
	t_operation	*tmp;

	if (!*op)
		*op = new;
	else
	{
		tmp = *op;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int				get_operation(t_asm *asm_f, t_token *curr, char *operation)
{
	t_operation	*new;
	size_t		n;
	char		*tmp;

	new = memalloc_op();
	if (!operation)
		return (FAILURE);
	n = token_len(operation);
	tmp = operation;
	new->op = op_token(operation, tmp, n, 0);
	new->len = token_len(operation);
	if (!check_operation(asm_f, new))
	{
		free_operation_lst(new);
		return (FAILURE);
	}
	if (!curr->operation)
		curr->operation = new;
	else
		add_op(&curr->operation, new);
	return (SUCCESS);
}
