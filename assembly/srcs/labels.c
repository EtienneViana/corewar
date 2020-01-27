/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:04:52 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/09 18:20:30 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_label_chars(char c)
{
	int		i;

	i = -1;
	while (LABEL_CHARS[++i])
		if (c == LABEL_CHARS[i])
			return (SUCCESS);
	return (FAILURE);
}

int			is_label(char *line)
{
	int		i;

	i = 0;
	while (is_label_chars(line[i]))
		++i;
	if (line[i] == LABEL_CHAR)
	{
		++i;
		return (i);
	}
	return (FAILURE);
}

int			is_label_instr(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '%' || line[i] == ':')
	{
		if (line[i] == ':')
			return (SUCCESS);
		i++;
	}
	if (line[i] == ':')
		return (SUCCESS);
	return (FAILURE);
}

void		add_label_to_tk_lst(t_label **labels, t_label *new)
{
	t_label	*tmp;

	if (!*labels)
		*labels = new;
	else
	{
		tmp = *labels;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		add_label_to_tk(t_token *curr, char *tmp, int len, bool was_label)
{
	t_label *label;

	if (was_label == false)
		curr->label = create_label(tmp, len);
	else if (was_label == true)
	{
		label = create_label(tmp, len);
		add_label_to_tk_lst(&curr->label, label);
	}
}
