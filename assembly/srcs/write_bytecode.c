/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytecode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:36:34 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/13 23:36:27 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				write_byte(int fd, unsigned int value, char nb)
{
	int				byte_offset;
	char			octet;

	byte_offset = 8 * (nb - 1);
	while (byte_offset >= 0)
	{
		octet = (value >> byte_offset) & 0xFF;
		write(fd, &octet, 1);
		byte_offset -= 8;
	}
}

void				write_bytecode2(int fd, t_token *token)
{
	t_token			*tmp;
	t_operation		*lst;
	size_t			i;

	tmp = token;
	while (tmp)
	{
		lst = tmp->operation;
		while (lst)
		{
			i = 2;
			write(fd, &lst->value[0], 1);
			if (lst->value[1] != 0)
				write(fd, &lst->value[1], 1);
			while (i <= lst->len)
			{
				write_byte(fd, lst->value[i]
				, calc_arg_size(check_arg(lst->op[i - 1]), lst->value[0] - 1));
				i++;
			}
			lst = lst->next;
		}
		tmp = tmp->next;
	}
}

int					write_bytecode(t_asm *asm_f, t_token *token)
{
	char			*bytecode;
	int				len;
	int				fd;

	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	if (!(bytecode = ft_memalloc(len)))
		return (errors(5));
	ft_memcpy(bytecode, asm_f->header, len);
	fd = open(asm_f->file, O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
	write(fd, bytecode, len);
	write_bytecode2(fd, token);
	free(bytecode);
	close(fd);
	return (SUCCESS);
}

void				print_tk_lst(t_token *token)
{
	t_token			*tmp;

	tmp = token;
	while (tmp)
	{
		ft_printf("tk index is %d\n", tmp->id);
		ft_printf("label is: in print {yellow}%s{reset}\n", tmp->label->name);
		ft_printf("tk size is %d\n", tmp->size);
		tmp = tmp->next;
	}
}

int					write_code(t_asm *asm_file, t_token *token)
{
	fill_value_tab(asm_file, token);
	if (!exec_code_size(asm_file->header, asm_file->size_tracker))
		return (FAILURE);
	write_bytecode(asm_file, token);
	ft_printf("Writing output program to %s\n", asm_file->file);
	return (SUCCESS);
}
