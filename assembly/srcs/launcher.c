/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:51:51 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/22 16:49:30 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			check_fd(char *file, t_asm *asm_f)
{
	int		len;
	char	*tmp;

	len = ft_strlen(file);
	if ((len < 2) || file[len - 1] != 's' || file[len - 2] != '.')
	{
		ft_printf("{red}Error:{reset} Wrong file format\n");
		return (FAILURE);
	}
	else if ((asm_f->fd = open(file, O_RDONLY)) == -1)
	{
		ft_printf("{red}Error:{reset}while opening the file descriptor\n");
		return (FAILURE);
	}
	if (!(asm_f->file = ft_memalloc(sizeof(char) * len + 2)))
		return (FAILURE);
	asm_f->origin = ft_strdup(file);
	tmp = asm_f->file;
	ft_strncpy(tmp, file, len - 1);
	asm_f->file = ft_strjoin(tmp, "cor");
	free(tmp);
	return (SUCCESS);
}

int			launcher(char *file, t_asm *asm_f, int data)
{
	t_token	*curr;
	int		ret;

	ret = 0;
	curr = init_token(0);
	if (check_fd(file, asm_f) && process_head_data(asm_f, data)
	&& read_asm_to_tokens(asm_f, curr, 0, ret))
	{
		if (!check_instr_label_in_tk(asm_f, asm_f->first_tk))
			return (errors(4));
		if (!write_code(asm_f, asm_f->first_tk))
			return (FAILURE);
	}
	else
	{
		asm_f->first_tk ? 0 : free(curr);
		return (FAILURE);
	}
	asm_f->first_tk ? 0 : free(curr);
	return (SUCCESS);
}
