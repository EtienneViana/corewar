/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:56:17 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/10 18:48:39 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				valid_line(char *tmp)
{
	if (tmp && (tmp[0] == '\0' || is_label_chars(tmp[0])
	|| tmp[0] == COMMENT_CHAR || tmp[0] == ALT_COMMENT_CHAR))
		return (1);
	else
		return (0);
}

int				line_not_valid(char *line, char *tmp)
{
	ft_printf("{red}Error{reset}: instruction not valid\n");
	ft_printf("line is: %s\n", tmp);
	ft_strdel(&line);
	return (FAILURE);
}

int				valid_op_separator(char *s, int cnt)
{
	if ((isspace(*s) && cnt == 0 && *(s + 1) != ' ')
	|| (isspace(*s) && *(s - 1) == ',') || (*s == SEPARATOR_CHAR)
	|| (*s == '\t') || (cnt == 0 && *s == '%'))
		return (1);
	else
		return (0);
}

void			print_operation(t_operation *operation)
{
	t_operation *tmp;
	size_t		i;

	tmp = operation;
	ft_printf("%12s |", "INSTR");
	ft_printf("%12s |", "OP_CODE");
	ft_printf("%12s |", "ARG 1");
	ft_printf("%12s |", "ARG 2");
	ft_printf("%12s |\n", "ARG 3");
	while (tmp)
	{
		i = 1;
		ft_printf("{green}%12s{reset} |", tmp->op[0]);
		ft_printf("{red}%12s{reset} |", "");
		while (i < tmp->len)
			ft_printf("{red}%12s{reset} |", tmp->op[i++]);
		ft_putchar('\n');
		i = 1;
		ft_printf("{yellow}%12d{reset} |", tmp->value[0]);
		while (i <= tmp->len)
			ft_printf("{yellow}%12d{reset} |", tmp->value[i++]);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void			print_list(t_token *token)
{
	t_label		*list;
	t_token		*tmp;

	tmp = token;
	while (tmp)
	{
		ft_printf("{blue}Token id is %d{reset}\n", tmp->id);
		list = tmp->label;
		while (list)
		{
			if (list->next != NULL)
				ft_printf("{yellow}%s{reset}, ", list->name);
			else
				ft_printf("{yellow}%s{reset}", list->name);
			list = list->next;
		}
		ft_putchar('\n');
		print_operation(tmp->operation);
		tmp = tmp->next;
	}
}
