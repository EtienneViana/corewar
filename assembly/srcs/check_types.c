/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:42:48 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/22 16:39:15 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_op(char *operation)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strequ(g_inst[i].name, operation))
			return (i);
		i++;
	}
	return (-1);
}

int		is_reg(char *argument)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(argument);
	if (len > 3 || len < 2)
		return (FAILURE);
	while (argument[++i])
		if (!ft_isdigit(argument[i]))
			return (FAILURE);
	if ((ft_atoi(argument + 1) < 1) || (ft_atoi(argument + 1) > REG_NUMBER))
		return (FAILURE);
	return (SUCCESS);
}

int		is_ind(char *argument)
{
	int i;

	i = 0;
	if (argument[0] == '-' || ft_isdigit(argument[0]))
	{
		while (argument[++i])
			if (!ft_isdigit(argument[i]))
				return (FAILURE);
	}
	else if (argument[0] == LABEL_CHAR)
	{
		while (argument[++i])
			if (!is_label_chars(argument[i]))
				return (FAILURE);
	}
	else
		return (FAILURE);
	return (SUCCESS);
}

int		is_dir(char *argument)
{
	if (!is_ind(argument + 1))
		return (FAILURE);
	return (SUCCESS);
}
