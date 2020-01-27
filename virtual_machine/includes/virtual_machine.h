/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <eviana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:56:35 by anrzepec          #+#    #+#             */
/*   Updated: 2020/01/22 18:35:23 by anrzepec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# include "libft.h"
# include "op.h"

/*
** ERROR CODES
*/

# define OH_OUI					0
# define OPTION_ERROR 			1
# define PLAYER_NUMBER_ERROR 	2
# define DUMP_ERROR				3
# define FILE_ERROR				4
# define PLAYER_OVERLOAD		5
# define NAME_ERROR				7
# define COMMENT_ERROR			8
# define EXEC_ERROR				9
# define MAGIC_ERROR			10
# define SIZE_ERROR				11
# define ALLOC_ERROR			12
# define VIS_ERROR				13
# define END_GAME				14

/*
** COLORS
*/

# define RED					"{red}"

# define _MAX_INT_				2147483647
# define _MIN_INT_				-2147483648
# define _MAX_UNS_INT_			4294967295

typedef struct			s_op
{
	char				name[6];
	int					params;
	int					type[3];
	int					op_number;
	int					cycles;
	char				description[50];
	int					ocp;
	int					dir_size;
	int					restr;
}						t_op;

typedef struct			s_player
{
	int					id;
	char				name[PROG_NAME_LENGTH + 4];
	char				comment[COMMENT_LENGTH + 4];
	unsigned int		size;
	char				exec[CHAMP_MAX_SIZE];
	int					init_pc;
	int					last_live;
}						t_player;

typedef struct			s_process
{
	int					id;
	int					master;
	int					carry;
	int					current_op;
	int					last_live;
	int					cycles_left;
	int					pc;
	int					reg[REG_NUMBER + 1];
	struct s_process	*next;
}						t_process;

typedef	struct			s_vm
{
	int					dump;
	int					vis;
	int					nb_args;
	int					nb_players;
	unsigned char		mem[MEM_SIZE];
	unsigned char		owner[MEM_SIZE];
	t_player			player[MAX_PLAYERS];
	t_process			*process;
	t_player			*last_live;
	int					cycles;
	int					nb_lives;
	int					cycles_to_die;
	int					nb_proc;
	int					nb_checks;
	int					last_verif;
	int					lives_since_check;
	int					nb_option;
	int					player_numbers[MAX_PLAYERS];
	int					live_tab[6];
	int					malloc_flag;
}						t_vm;

typedef struct			s_param
{
	int					n[3];
	int					c[3];
	int					valid;
}						t_param;

extern t_op				g_op_tab[17];

/*
** Init
*/
t_vm					*init_vm(int ac);
void					init_players(t_vm *vm);
void					create_arena(t_vm *vm);
int						load_process_list(t_vm *vm);

/*
** Parsing
*/
int						parse_option(t_vm *vm, char **av, int *i);
int						parse_player(t_vm *vm, char **av, int i);
int						check_player_numbers(t_vm *vm, int player_nb);
int						check_extension(char *name);
void					check_empty(t_vm *vm);
/*
** Runtime
*/
int						exec_machine(t_vm *vm);
t_param					set_params(t_vm *vm, t_process *proc,
							int pc, int *offset);
int						process_review(t_vm *vm, t_process *process);
int						life_check(t_vm *vm);
int						get_code(char ocp);
int						check_ocp(t_process *proc, char ocp);
int						get_t_code(char ocp);

/*
** Operations
*/
int						op_live(t_vm *vm, t_process *proc);
int						op_ld(t_vm *vm, t_process *proc);
int						op_st(t_vm *vm, t_process *proc);
int						op_add(t_vm *vm, t_process *proc);
int						op_sub(t_vm *vm, t_process *proc);
int						op_and(t_vm *vm, t_process *proc);
int						op_or(t_vm *vm, t_process *proc);
int						op_xor(t_vm *vm, t_process *proc);
int						op_zjmp(t_vm *vm, t_process *proc);
int						op_ldi(t_vm *vm, t_process *proc);
int						op_sti(t_vm *vm, t_process *proc);
int						op_fork(t_vm *vm, t_process *proc);
int						op_lld(t_vm *vm, t_process *proc);
int						op_lldi(t_vm *vm, t_process *proc);
int						op_lfork(t_vm *vm, t_process *proc);
int						op_aff(t_vm *vm, t_process *proc);

/*
** Tools
*/
int						get_next_number(t_vm *vm);
int						is_valid_op(int opcode);
int						is_valid_reg(int reg);
void					init_registers(t_process *process);
void					copy_registers(t_process *new, t_process *proc);
int						long_rel_address(t_process *proc, int add1, int add2);
int						read_address(t_vm *vm, int addr, size_t bytes);
int						read_bytes(unsigned char *mem, size_t size);
void					write_to_address(t_vm *vm, t_process *proc,
							int addr, int to_write);
int						idx_mod(int addr);
int						modulo_mem_size(int addr);

/*
** Error management
*/
int						init_error(int error, t_vm *vm);
void					free_machine(t_vm *vm);

/*
** Print
*/
void					print_usage(void);
int						print_dump(t_vm *vm);
int						print_arena(t_vm *vm);
void					print_pannel(t_vm *vm, int line, int *players);
int						get_player_color(t_vm *vm, int players);

#endif
