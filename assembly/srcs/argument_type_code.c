/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_type_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:50:42 by yabecret          #+#    #+#             */
/*   Updated: 2019/11/27 18:20:05 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**T_REG	r	01	1 byte
**T_DIR	%	10	The size T_DIR
**T_IND	-	11	2 bytes
*/

/*
**	01 00 00 00 = 64  : 0x40
**	10 00 00 00 = 128 : 0x80
**	11 00 00 00 = 192 : 0xC0
*/

int	get_arg1(char *arg, int code)
{
	int type;

	type = check_arg(arg);
	if (type == T_REG)
		code += 0x40;
	if (type == T_DIR)
		code += 0x80;
	if (type == T_IND)
		code += 0xC0;
	return (code);
}

/*
**	00 01 00 00 = 16 : 0x10
**	00 10 00 00 = 32 : 0x20
**	00 11 00 00 = 48 : 0x30
*/

int	get_arg2(char *arg, int code)
{
	int type;

	type = check_arg(arg);
	if (type == T_REG)
		code += 0x10;
	if (type == T_DIR)
		code += 0x20;
	if (type == T_IND)
		code += 0x30;
	return (code);
}

/*
**	00 00 01 00 = 4  : 0x4
**	00 00 10 00 = 8  : 0x8
**	00 00 11 00 = 12 : 0xC
*/

int	get_arg3(char *arg, int code)
{
	int type;

	type = check_arg(arg);
	if (type == T_REG)
		code += 0x4;
	if (type == T_DIR)
		code += 0x8;
	if (type == T_IND)
		code += 0xC;
	return (code);
}

int	get_arg_type_code(t_operation *operation)
{
	int code;

	code = 0;
	code = get_arg1(operation->op[1], code);
	if (operation->len >= 3)
		code = get_arg2(operation->op[2], code);
	if (operation->len >= 4)
		code = get_arg3(operation->op[3], code);
	return (code);
}
