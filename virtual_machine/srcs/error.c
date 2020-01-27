/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:22:13 by anrzepec          #+#    #+#             */
/*   Updated: 2020/01/22 16:49:41 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	free_machine(t_vm *vm)
{
	t_process *tracer;
	t_process *tmp;

	tracer = vm->process;
	while (tracer)
	{
		tmp = tracer;
		tracer = tracer->next;
		free(tmp);
	}
	free(vm);
}

void	print_usage_war(void)
{
	ft_printf(
		"                   />\n");
	ft_printf(
	"      ()          //---------------------------(\n");
	ft_printf(
		"     (*)OXOXOXOXO(*>        --COREWAR--         {red}\\{eoc}\n");
	ft_printf(
		"      ()          \\\\-----------{red}------------------){eoc}\n");
	ft_printf(
		"                   \\>                          {red}  \"{eoc}\n");
	ft_printf(
		"                                                {red}'{eoc}\n");
}

void	print_usage(void)
{
	print_usage_war();
	ft_printf("> ./corewar [-v] cycle_refresh [[-dump] nbr_cycles] ");
	ft_printf("[[-n number]");
	ft_printf(" champion1.cor] ...\n\n{red}-->     FLAGS{eoc}\n\n-v  ");
	ft_printf("    ");
	ft_printf("Visualization.\n        Example: ./corewar -v 500 champ1.cor ");
	ft_printf("champ2.cor\n\n-n      Player number selection.\n        ");
	ft_printf("Example: > ./corewar -n 4 champ1.cor -n 2 champ2.cor\n        ");
	ft_printf("Corewar will auto-assign where no selection is made.\n\n");
	ft_printf("-dump  ");
	ft_printf(" Dump memory.\n        Example: > ./corewar -dump 27 ");
	ft_printf("champ1.cor ");
	ft_printf("champ2.cor\n        Here, Corewar will dump memory after 27");
	ft_printf(" cycles.\n        Corewar can only accept 1 -dump argument.\n");
}

void	init_error_extend(int error)
{
	if (error == SIZE_ERROR)
		ft_printf("Invalid Champion: Exceeds Authorized Size.\n");
	if (error == ALLOC_ERROR)
	{
		ft_printf("Malloc() fail. (Please report this incident to the ");
		ft_printf("dev team)\n");
	}
	if (error == VIS_ERROR)
		ft_printf("Invalid Value For Visualization Refresh Rate.\n");
	ft_printf("\n{eoc}");
	if (error != ALLOC_ERROR)
		print_usage();
}

int		init_error(int error, t_vm *vm)
{
	free_machine(vm);
	ft_printf("{red}\n -> ");
	if (error == OPTION_ERROR)
		ft_printf("Invalid Option.\n");
	if (error == PLAYER_NUMBER_ERROR)
		ft_printf("Invalid Champion Number.\n");
	if (error == DUMP_ERROR)
		ft_printf("Invalid Memory Dump Value.\n");
	if (error == FILE_ERROR)
		ft_printf("Invalid Path to Champion.\n");
	if (error == PLAYER_OVERLOAD)
		ft_printf("Too Many Champions.\n");
	if (error == NAME_ERROR)
		ft_printf("Invalid Champion Name.\n");
	if (error == COMMENT_ERROR)
		ft_printf("Invalid Champion Comment.\n");
	if (error == EXEC_ERROR)
		ft_printf("Invalid Champion Executable.\n");
	if (error == MAGIC_ERROR)
		ft_printf("Invalid Champion Magic Number.\n");
	init_error_extend(error);
	return (1);
}
