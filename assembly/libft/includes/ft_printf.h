/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:50:32 by yabecret          #+#    #+#             */
/*   Updated: 2020/01/10 12:03:16 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define BUFF_SIZE 128

/*
**# define PRINTFRET __attribute__ ((__format__(printf, 1, 2))) int
*/

/*
**-------------------------------- FLAGS & SPEC ----------------------------
*/

/*
** F_MINUS (1 << 0)  -->  '-'	0000 0000 0000 00001
** F_PLUS (1 << 1)   -->  '+'	0000 0000 0000 00010
** F_ZERO (1 << 2)   -->  '0'	0000 0000 0000 00100
** F_SPACE (1 << 3)  -->  ' '	0000 0000 0000 01000
** F_HASH (1 << 4)   -->  '#'	0000 0000 0000 10000
** S_SHORT (1 << 5)  -->  'h'	0000 0000 0001 00000
** S_LONG (1 << 6)   -->  'l'	0000 0000 0010 00000
** S_DOUBLE (1 << 7) -->  'L'	0000 0000 0100 00000
** S_INTMAX (1 << 8) -->  'j'	0000 0000 1000 00000
** S_SIZE_T (1 << 9) -->  'z'	0000 0001 0000 00000
** S_CHAR (1 << 10)  -->  'hh'	0000 0010 0000 00000
** S_LLONG (1 << 11) -->  'll'	0000 0100 0000 00000
*/

# define F_MINUS 1
# define F_PLUS 2
# define F_ZERO 4
# define F_SPACE 8
# define F_HASH 16
# define S_SHORT 32
# define S_LONG 64
# define S_DOUBLE 128
# define S_INTMAX 256
# define S_SIZE_T 512
# define S_CHAR 1024
# define S_LLONG 2048

/*
**----------------------------------- BASES -------------------------------
*/

# define B_DEC 10
# define B_BIN 2
# define B_OCT 4
# define B_HEX 16

/*
**----------------------------------- COLORS -------------------------------
*/

/*
**# define C_CLEAR		(\033[2K)
**# define C_UP			(\033[A)
**# define C_NOCOLOR		(\033[0m)
**# define C_BOLD			(\033[1m)
**# define C_UNDERLINE	(\033[4m)
**# define C_BLINKING		(\033[5m)
**# define C_BLACK		(\033[1;30m)
**# define C_RED			(\033[1;31m)
**# define C_GREEN		(\033[1;32m)
**# define C_YELLOW		(\033[1;33m)
**# define C_BLUE			(\033[1;34m)
**# define C_VIOLET		(\033[1;35m)
**# define C_CYAN			(\033[1;36m)
**# define C_WHITE		(\033[1;37m)
*/

/*
**----------------------------------- STRUCT -------------------------------
*/

typedef struct	s_printf
{
	char	conv;
	int		flags;
	int		precision;
	int		min_length;
	int		neg;
	int		base;
	int		index;
	int		ret;
	int		extended_prec;
	int		last_up;
	int		fd;
	va_list ap;
	char	buff[BUFF_SIZE];
	char	*format;
}				t_printf;

typedef int(*t_f_conv)(t_printf*);

typedef struct	s_conv
{
	char		*c;
	t_f_conv	funct;
}				t_conv;

typedef int(*t_f_color)(t_printf*, int i);

typedef struct	s_color
{
	char		*color;
	t_f_color	funct;
}				t_color;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

int				color_to_fct(t_printf *pf);

/*
**---------------------------------- OPTIONS -------------------------------
*/

int				parse_arg(t_printf *pf);
int				find_char(char *str, char c);
int				find_conv(char *str, char c);

/*
**---------------------------------- CONVERS -------------------------------
*/

int				get_conversion(t_printf *pf);
int				conv_to_fct(t_printf *pf);
int				not_specifier(t_printf *pf);
int				d_conv(t_printf *pf, intmax_t nb, uintmax_t new);
int				u_conv(t_printf *pf, uintmax_t nb);
int				x_conv(t_printf *pf, uintmax_t nb);
int				o_conv(t_printf *pf, uintmax_t nb);
int				c_conv(t_printf *pf, char c);
int				w_conv(t_printf *pf, wint_t wc);
int				f_conv(t_printf *pf, long double nb, int prec);
long double		ft_round(t_printf *pf, long double nb, int prec);

/*
**---------------------------------- CASTARG -------------------------------
*/

intmax_t		ft_castint(t_printf *pf);
uintmax_t		ft_castuint(t_printf *pf);

/*
**---------------------------------- PT_FUNCT ------------------------------
*/

int				int_arg(t_printf *pf);
int				dou_arg(t_printf *pf);
int				c_arg(t_printf *pf);
int				s_arg(t_printf *pf);
int				p_arg(t_printf *pf);
int				f_arg(t_printf *pf);
int				pct_arg(t_printf *pf);
int				man_arg(t_printf *pf);

/*
**-------------------------------- HANDLE_BUFF -----------------------------
*/

void			reset_struct(t_printf *pf);
void			reset(t_printf *pf);
void			check_buff(t_printf *pf);
int				end(t_printf *pf, int i);
int				handle_buff(t_printf *pf, char *str, int i, int n);

/*
**---------------------------------- PADDING -------------------------------
*/

void			hash_padding(t_printf *pf);
void			padding(t_printf *pf, int prec, int len, uintmax_t nb);
void			u_padding(t_printf *pf, int prec, int len, uintmax_t nb);
void			min_padding(t_printf *pf, char c, int len);
void			char_padding(t_printf *pf, char c);

/*
**----------------------------------- CHECK --------------------------------
*/

int				check_plus(t_printf *pf, int len, int prec);
int				check_zero(t_printf *pf, int len);
int				check_ohash(t_printf *pf, int prec);
int				check_xhash(t_printf *pf, int prec, int nb);
uintmax_t		check_neg(t_printf *pf, intmax_t nb, uintmax_t new);

#endif
