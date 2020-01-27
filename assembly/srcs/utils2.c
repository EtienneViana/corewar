/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:59:37 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/22 14:50:03 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int			is_comment(char c)
{
	if (c == COMMENT_CHAR || c == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

int			is_valid_chars(char c)
{
	int		i;

	i = -1;
	while (VALID_CHARS[++i])
		if (c == VALID_CHARS[i])
			return (SUCCESS);
	return (FAILURE);
}

void		print_op(t_operation *operation)
{
	t_operation *tmp;
	size_t		i;

	tmp = operation;
	while (tmp)
	{
		i = 1;
		ft_printf("{green}%s{reset} |", tmp->op[0]);
		while (i < tmp->len)
			ft_printf("{red}%s{reset} |", tmp->op[i++]);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

int			ft_strcntchr(char *str, char c)
{
	int		cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == c)
			cnt++;
		str++;
	}
	return (cnt);
}
