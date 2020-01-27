/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:49:32 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/10 13:55:25 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			head_data_error(t_asm *asm_f, int data)
{
	if (data == -2)
	{
		if (!asm_f->name)
			ft_printf("{red}Error:{reset} Wrong format for Name\n");
		else if (!asm_f->comment)
			ft_printf("{red}Error:{reset} Wrong format for Comment\n");
	}
	else
	{
		if (!asm_f->name)
			ft_printf("{red}Error:{reset} Missing Name\n");
		else if (!asm_f->comment)
			ft_printf("{red}Error:{reset} Missing Comment\n");
	}
	return (FAILURE);
}

int			head_length_error(t_asm *asm_f)
{
	if (ft_strlen(asm_f->name) > PROG_NAME_LENGTH)
		ft_printf("{red}Error:{reset} Name length too long\n");
	else if (ft_strlen(asm_f->comment) > COMMENT_LENGTH)
		ft_printf("{red}Error:{reset} Comment length too long\n");
	return (FAILURE);
}

int			errors(int err)
{
	if (err == 1)
		ft_printf("{red}Error:{reset} Instruction format not valid\n");
	else if (err == 2)
		ft_printf("{red}Error:{reset} Wrong nb of args{reset}\n");
	else if (err == 3)
		ft_printf("{red}Error:{reset} Wrong argument type{reset}\n");
	else if (err == 4)
		ft_printf("{red}Error:{reset} Label does not exist\n");
	else if (err == 5)
		ft_printf("{red}Error:{reset} Memory allocation error./\n");
	else if (err == 6)
		ft_printf("{red}Error:{reset} Type doesn't match w/ inst./\n");
	return (FAILURE);
}
