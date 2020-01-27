/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:33:44 by yabecret          #+#    #+#             */
/*   Updated: 2020/01/10 18:33:49 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		hexdump_name(t_asm *asm_file, int i)
{
	int		j;

	j = 0;
	while (asm_file->name[j])
	{
		asm_file->header[i + j] = asm_file->name[j];
		j++;
	}
}

void		hexdump_comment(t_asm *asm_file, int i)
{
	int		j;

	j = 0;
	while (asm_file->comment[j])
	{
		asm_file->header[i + j] = asm_file->comment[j];
		j++;
	}
}

void		byte(char *code, unsigned int value, char nb)
{
	int		byte_offset;
	int		i;

	byte_offset = 8 * (nb - 1);
	i = 0;
	while (byte_offset >= 0)
	{
		code[i] = (value >> byte_offset) & 0xFF;
		byte_offset -= 8;
		i++;
	}
}

void		set_magic_header(t_asm *asm_file)
{
	byte(asm_file->header, COREWAR_EXEC_MAGIC, 4);
	hexdump_name(asm_file, 4);
	hexdump_comment(asm_file, PROG_NAME_LENGTH + 12);
}

int			exec_code_size(char *header, int size)
{
	if (size > 682)
	{
		ft_printf("{red}Error:{reset} Exec code size too big\n");
		return (FAILURE);
	}
	header[PROG_NAME_LENGTH + 10] = size >> 8;
	header[PROG_NAME_LENGTH + 11] = size & 0xFF;
	return (1);
}
