/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:51:00 by anrzepec          #+#    #+#             */
/*   Updated: 2020/01/22 16:48:20 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int			usage_check(int ac)
{
	if (ac == 1)
	{
		print_usage();
		return (1);
	}
	return (0);
}

int			load_players(char **av, t_vm *vm)
{
	int i;
	int ret;
	int err;

	i = 0;
	while (++i < vm->nb_args)
	{
		if (av[i] && av[i][0] == '-')
		{
			if ((ret = parse_option(vm, av, &i)))
				return (ret);
		}
		else if ((err = parse_player(vm, av, i)))
			return (err);
	}
	return (vm->nb_players > 0 ? 0 : 1);
}

void		loading_position(t_vm *vm)
{
	t_process	*tracer;
	int			div;
	int			i;

	i = vm->nb_players - 1;
	div = MEM_SIZE / vm->nb_players;
	tracer = vm->process;
	while (tracer)
	{
		tracer->pc = div * i;
		i--;
		tracer = tracer->next;
	}
}

int			main(int ac, char **av)
{
	int		err;
	t_vm	*vm;

	err = 0;
	if (usage_check(ac))
		return (1);
	if (!(vm = init_vm(ac)))
		return (init_error(ALLOC_ERROR, vm));
	if ((err = load_players(av, vm)))
		return (init_error(err, vm));
	if ((load_process_list(vm)) == ALLOC_ERROR)
		return (ALLOC_ERROR);
	loading_position(vm);
	create_arena(vm);
	vm->last_live = &vm->player[vm->nb_players - 1];
	if (exec_machine(vm) == ALLOC_ERROR)
		return (init_error(ALLOC_ERROR, vm));
	free_machine(vm);
	ft_printf("You have been playing Corewar, feel free to donate!\n");
	return (0);
}
