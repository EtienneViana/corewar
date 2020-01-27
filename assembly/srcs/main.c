/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:16:19 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/22 16:45:47 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char **argv)
{
	t_asm	asm_f;
	int		data;

	asm_f.was_label = false;
	ft_bzero(&asm_f, sizeof(t_asm));
	data = 0;
	if (argc == 2)
	{
		launcher(argv[1], &asm_f, data);
		free_asm_and_token(&asm_f);
	}
	else if (argc == 3 && (ft_strcmp(argv[2], "-p") == 0))
	{
		if (launcher(argv[1], &asm_f, data))
			print_list(asm_f.first_tk);
		free_asm_and_token(&asm_f);
	}
	else
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
