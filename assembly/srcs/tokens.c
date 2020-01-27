/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:38:29 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/10 17:10:24 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_token(t_token **tokens, t_token *new)
{
	t_token *tmp;

	if (!*tokens)
		*tokens = new;
	else
	{
		tmp = *tokens;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		*tokens = tmp->next;
	}
}

t_token		*new_tk_with_label(t_asm *asm_f, t_token *curr, char *tmp, int i)
{
	t_token *token;

	token = init_token(i);
	add_token(&curr, token);
	curr->label = create_label(tmp, asm_f->len);
	curr->size = asm_f->size_tracker;
	asm_f->was_label = true;
	return (curr);
}

int			parse_operation(t_asm *asm_f, t_token *curr, char *tmp, int i)
{
	char	*operation;

	operation = remove_comments(tmp);
	(i == 0) ? (asm_f->first_tk = curr) : 0;
	if (!get_operation(asm_f, curr, operation))
	{
		ft_strdel(&operation);
		return (FAILURE);
	}
	ft_strdel(&operation);
	return (SUCCESS);
}

char		*new_label(t_asm *asm_f, t_token *curr, char *tmp, int i)
{
	add_label_to_tk(curr, tmp, asm_f->len, asm_f->was_label);
	(i == 0) ? (asm_f->first_tk = curr) : 0;
	asm_f->was_label = true;
	tmp = tmp + asm_f->len;
	return (tmp);
}

int			read_asm_to_tokens(t_asm *asm_f, t_token *curr, int i, int ret)
{
	char	*tmp;
	char	*line;

	while ((ret = get_next_line(asm_f->fd, &line) > 0))
	{
		tmp = rm_space_around(line);
		if (valid_line(tmp))
		{
			if (((asm_f->len = is_label(tmp)) != 0) && !curr->operation)
				tmp = new_label(asm_f, curr, tmp, i);
			else if (((asm_f->len = is_label(tmp)) != 0) && curr->operation)
			{
				curr = new_tk_with_label(asm_f, curr, tmp, ++i);
				tmp = tmp + asm_f->len;
			}
			tmp = rm_space_around(tmp);
			if (ft_isalpha(tmp[0]) && ((asm_f->len = is_label(tmp)) == 0))
				if (!parse_operation(asm_f, curr, tmp, i))
					return (free_str(line));
		}
		else
			return (line_not_valid(line, tmp));
		ft_strdel(&line);
	}
	return (SUCCESS);
}
