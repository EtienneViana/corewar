/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:37:29 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/22 14:57:00 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** nameless champion, champion with no comment, champ with name too long
**	champion with no code
**	-> refusing to run the champion
** following errors must be handle :
** unknown instruction
** wrong arg nbr for instruct
** wrong type of arg for instruct
** wrong char in a label
** reference to an unexisting label from a direct or an indirect
** every lexical error lk a wrong char to finish a label, a direct ...
*/

int			is_fmt_valid(char *str)
{
	int		i;

	i = 1;
	if (str && str[0] == '"')
	{
		while (str[i] && str[i] != '"')
			i++;
		if (str[i] != '"')
			return (0);
		if (str[i + 1] == '\0')
			return (1);
		while (ft_isspace(str[i + 1]))
			i++;
		if (str[i + 1] == '\0' || str[i + 1] == COMMENT_CHAR
		|| str[i + 1] == ALT_COMMENT_CHAR)
			return (1);
	}
	return (0);
}

char		*rm_brackets(char *str)
{
	int		len;
	char	*tmp;

	tmp = str + 1;
	len = ft_strlen(tmp);
	tmp[len - 1] = '\0';
	return (tmp);
}

int			get_name_comment(t_asm *asm_f, char *line, int data, int i)
{
	if ((ft_strncmp(line, NAME_CMD_STRING, 4) == 0) && !asm_f->name)
	{
		line = line + 5;
		while (ft_isspace(line[i]))
			i++;
		if (is_fmt_valid(line + i))
		{
			asm_f->name = ft_strdup(rm_brackets(line + i));
		}
		else
			data = -2;
	}
	else if ((ft_strncmp(line, COMMENT_CMD_STRING, 7) == 0) && !asm_f->comment)
	{
		line = line + 8;
		while (ft_isspace(line[i]))
			i++;
		if (is_fmt_valid(line + i))
			asm_f->comment = ft_strdup(rm_brackets(line + i));
		else
			data = -2;
	}
	else
		data = -1;
	return (data);
}

int			parse_name_comment(t_asm *asm_f, char *line, int data)
{
	int i;

	i = 0;
	if (line && line[0] != COMMENT_CHAR && line[0] != ALT_COMMENT_CHAR
	&& line[0] != '\0' && line[0] != '\n')
	{
		data = get_name_comment(asm_f, line, data, i);
		if (data < 0)
			return (data);
	}
	return (data);
}

int			process_head_data(t_asm *asm_f, int data)
{
	int		ret;
	char	*line;
	char	*tmp;

	tmp = NULL;
	while (data >= 0 && data < 2 && (ret = get_next_line(asm_f->fd, &line) > 0))
	{
		tmp = add_next_line(asm_f, line, tmp);
		if (tmp && tmp[ft_strlen(tmp) - 1] == '"' && asm_f->cnt_brckt > 1)
		{
			asm_f->cnt_brckt = 0;
			data = parse_name_comment(asm_f, rm_space_around(tmp), data);
			ft_strdel(&tmp);
			data >= 0 ? data++ : 0;
		}
		ft_strdel(&line);
	}
	ft_strdel(&tmp);
	if (ret < 0 || !asm_f->name || !asm_f->comment)
		return (head_data_error(asm_f, data));
	if (ft_strlen(asm_f->name) > PROG_NAME_LENGTH
	|| ft_strlen(asm_f->comment) > COMMENT_LENGTH)
		return (head_length_error(asm_f));
	set_magic_header(asm_f);
	return (SUCCESS);
}
