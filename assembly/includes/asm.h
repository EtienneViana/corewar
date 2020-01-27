/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:53:17 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/22 14:37:30 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# define FAILURE 0
# define SUCCESS 1
# define VALID_CHARS "abcdefghijklmnopqrstuvwxyz \t_,%:-0123456789"

typedef	struct			s_inst
{
	char				*name;
	uint8_t				code;
	uint8_t				nb_args;
	uint8_t				args_type[3];
	bool				arg_type_code;
	uint8_t				t_dir_size;
}						t_inst;

static	t_inst			g_inst[16] = {

	{
		.name			= "live",
		.code			= 0x01,
		.nb_args		= 1,
		.args_type		= {T_DIR, 0, 0},
		.arg_type_code	= false,
		.t_dir_size		= 4,
	},
	{
		.name			= "ld",
		.code			= 0x02,
		.nb_args		= 2,
		.args_type		= {T_DIR | T_IND, T_REG, 0},
		.arg_type_code	= true,
		.t_dir_size		= 4,
	},
	{
		.name			= "st",
		.code			= 0x03,
		.nb_args		= 2,
		.args_type		= {T_REG, T_REG | T_IND, 0},
		.arg_type_code	= true,
		.t_dir_size		= 4,
	},
	{
		.name			= "add",
		.code			= 0x04,
		.nb_args		= 3,
		.args_type		= {T_REG, T_REG, T_REG},
		.arg_type_code	= true,
		.t_dir_size		= 4,
	},
	{
		.name			= "sub",
		.code			= 0x05,
		.nb_args		= 3,
		.args_type		= {T_REG, T_REG, T_REG},
		.arg_type_code	= true,
		.t_dir_size		= 4,
	},
	{
		.name			= "and",
		.code			= 0x06,
		.nb_args		= 3,
		.args_type		= {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.arg_type_code	= true,
		.t_dir_size		= 4,
	},
	{
		.name			= "or",
		.code			= 0x07,
		.nb_args		= 3,
		.args_type		= {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.arg_type_code	= true,
		.t_dir_size		= 4,
	},
	{
		.name			= "xor",
		.code			= 0x08,
		.nb_args		= 3,
		.args_type		= {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.arg_type_code	= true,
		.t_dir_size		= 4,
	},
	{
		.name			= "zjmp",
		.code			= 0x09,
		.nb_args		= 1,
		.args_type		= {T_DIR, 0, 0},
		.arg_type_code	= false,
		.t_dir_size		= 2,
	},
	{
		.name			= "ldi",
		.code			= 0x0a,
		.nb_args		= 3,
		.args_type		= {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.arg_type_code	= true,
		.t_dir_size		= 2,
	},
	{
		.name			= "sti",
		.code			= 0x0b,
		.nb_args		= 3,
		.args_type		= {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.arg_type_code	= true,
		.t_dir_size		= 2,
	},
	{
		.name			= "fork",
		.code			= 0x0c,
		.nb_args		= 1,
		.args_type		= {T_DIR, 0, 0},
		.arg_type_code	= false,
		.t_dir_size		= 2,
	},
	{
		.name			= "lld",
		.code			= 0x0d,
		.nb_args		= 2,
		.args_type		= {T_DIR | T_IND, T_REG, 0},
		.arg_type_code	= true,
		.t_dir_size		= 4,
	},
	{
		.name			= "lldi",
		.code			= 0x0e,
		.nb_args		= 3,
		.args_type		= {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.arg_type_code	= true,
		.t_dir_size		= 2,
	},
	{
		.name			= "lfork",
		.code			= 0x0f,
		.nb_args		= 1,
		.args_type		= {T_DIR, 0, 0},
		.arg_type_code	= false,
		.t_dir_size		= 2,
	},
	{
		.name			= "aff",
		.code			= 0x10,
		.nb_args		= 1,
		.args_type		= {T_REG, 0, 0},
		.arg_type_code	= true,
		.t_dir_size		= 4,
	},
};

typedef struct			s_operation
{
	int					size;
	size_t				len;
	char				**op;
	int					*value;
	struct s_operation	*next;
}						t_operation;

typedef struct			s_label
{
	char				*name;
	int					pos;
	struct s_label		*next;
}						t_label;

typedef struct			s_token
{
	int					id;
	int					pos;
	int					size;
	int					nb_operations;
	t_label				*label;
	t_operation			*operation;
	struct s_token		*next;
}						t_token;

typedef struct			s_asm
{
	int					fd;
	int					pos;
	int					err;
	int					size_tracker;
	int					len;
	int					cnt_brckt;
	bool				was_label;
	char				*origin;
	char				*file;
	char				*name;
	char				*comment;
	char				header[16 + PROG_NAME_LENGTH + COMMENT_LENGTH];
	t_token				*first_tk;
}						t_asm;

/*
**						MAIN
*/

int						main(int argc, char **argv);

/*
**						LAUNCHER
*/

int						check_fd(char *file, t_asm *asm_f);
int						launcher(char *file, t_asm *asm_f, int data);

/*
**						HEADER
*/

void					hexdump_name(t_asm *asm_file, int i);
void					hexdump_comment(t_asm *asm_file, int i);
void					bytecode(char *code, int32_t data, size_t size);
void					set_magic_header(t_asm *asm_f);
int						exec_code_size(char *header, int size);

/*
**						PROCESS HEAD
*/

int						parse_name_comment(t_asm *asm_f, char *line, int data);
int						get_name_comment(t_asm *asm_f, char *line
						, int data, int i);
int						is_fmt_valid(char *str);
int						process_head_data(t_asm *asm_f, int data);

/*
**                 		INIT
*/

t_token					*init_token(int index);
t_label					*create_label(char *line, int len);
t_operation				*memalloc_op(void);

/*
**							OPERATIONS
*/

char					**op_token(char *s, char *tmp, size_t nb_args, int cnt);
void					add_op(t_operation **op, t_operation *new);
int						get_operation(t_asm *asm_f, t_token *curr
						, char *operation);

/*
**						CHECK OPERATIONS
*/

int						calc_arg_size(int type, int index);
int						check_type(int type, int i, int index);
int						check_arg(char *argument);
int						check_arg_type(t_asm *asm_f
						, t_operation *operation, int index);
int						check_operation(t_asm *asm_f, t_operation *operation);

/*
**						CHECK TYPE
*/

int						is_dir(char *argument);
int						is_ind(char *argument);
int						is_reg(char *argument);
int						is_op(char *operation);

/*
**						CHECK LABELS
*/

int						find_label(t_token *token, char *label);
int						check_instr_label_in_tk(t_asm *asm_f, t_token *token);

/*
**						LABELS
*/

int						is_label_chars(char c);
int						is_label(char *line);
int						is_label_instr(char *line);
void					add_label_to_tk(t_token *curr, char *tmp
						, int len, bool was_label);
void					add_label_to_tk_lst(t_label **labels, t_label *new);

/*
**						TOKENS
*/

int						read_asm_to_tokens(t_asm *asm_f, t_token *cur, int i
						, int ret);
void					add_token(t_token **tokens, t_token *new);
int						parse_operation(t_asm *asm_f, t_token *curr
						, char *tmp, int i);
char					*new_label(t_asm *asm_f, t_token *curr
						, char *tmp, int i);
t_token					*new_tk_with_label(t_asm *asm_f, t_token *curr
						, char *tmp, int i);

/*
**						SIZE
*/

int						total_size(t_token *token);
void					fill_value2(t_asm *asm_file, t_operation *operation
						, int i);
void					fill_value4(t_asm *asm_file, t_operation *operation
						, int i);
int						fill_arg_value(t_asm *asm_file, t_operation *operation);
int						fill_value_tab(t_asm *asm_file, t_token *token);

/*
**						WRITE
*/

int						write_bytecode(t_asm *asm_f, t_token *token);
int						write_code(t_asm *asm_file, t_token *token);

/*
**						UTILS
*/

void					free_tab(char **tab);
char					*erase_last_char(char *str);
char					*rm_space_around(char *str);
char					*remove_comments(char *tmp);
char					*add_next_line(t_asm *asm_f, char *line, char *tmp);

/*
**						UTILS2
*/

int						ft_isspace(char c);
int						is_comment(char c);
int						is_valid_chars(char c);
void					print_op(t_operation *operation);
int						ft_strcntchr(char *str, char c);

/*
**						UTILS3
*/

int						valid_line(char *tmp);
int						line_not_valid(char *line, char *tmp);
int						valid_op_separator(char *s, int cnt);
void					print_operation(t_operation *operation);
void					print_list(t_token *token);

/*
**						ERRORS
*/

int						head_data_error(t_asm *asm_f, int data);
int						head_length_error(t_asm *asm_f);
int						errors(int err);

/*
**						FREE
*/

int						free_str(char *line);
int						free_operation(t_operation *operation);
int						free_operation_lst(t_operation *operation);
int						free_label_lst(t_label *label);
int						free_token(t_token *token);
int						free_token_lst(t_token *token);
int						free_asm_and_token(t_asm *asm_f);

/*
**						CONVERSIONS
*/

unsigned int			conv_decimal(long value);
unsigned int			conv_binary_to_dec(char *b);
char					*get_bits(const unsigned long v);

/*
**						ARGUMENT_TYPE_CODE
*/

int						get_arg_type_code(t_operation *operation);

#endif
