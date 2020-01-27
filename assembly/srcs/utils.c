/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:07:30 by mjouffro          #+#    #+#             */
/*   Updated: 2020/01/22 14:55:56 by mjouffro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
			ft_strdel(&tab[i++]);
		free(tab);
	}
}

char		*erase_last_char(char *str)
{
	char	*tmp;

	tmp = str + 1;
	tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

char		*rm_space_around(char *str)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	new = NULL;
	i = ft_strlen(str) - 1;
	while (i > 0 && ft_isspace(str[i]))
	{
		if (ft_isspace(str[i]))
			str[i] = '\0';
		i--;
	}
	while (str[j] && ft_isspace(str[j]))
		j++;
	new = str + j;
	return (new);
}

char		*remove_comments(char *tmp)
{
	size_t	i;
	size_t	len;
	char	*operation;

	i = 0;
	len = ft_strlen(tmp);
	operation = ft_strnew(len);
	while (tmp[i] != ALT_COMMENT_CHAR
	&& tmp[i] != COMMENT_CHAR && tmp[i] != '\0' && tmp[i] != '\n')
	{
		operation[i] = tmp[i];
		++i;
	}
	while (i < len)
	{
		operation[i] = '\0';
		++i;
	}
	operation = rm_space_around(operation);
	return (operation);
}

char		*add_next_line(t_asm *asm_f, char *line, char *tmp)
{
	int		len;
	char	*new;
	char	*tmp2;

	len = ft_strlen(line);
	asm_f->cnt_brckt += ft_strcntchr(line, '"');
	if (line[0] == COMMENT_CHAR || line[0] == ALT_COMMENT_CHAR)
		return (NULL);
	if (line[len] != '"')
	{
		if (tmp == NULL)
		{
			new = ft_strdup(line);
			ft_strdel(&tmp);
		}
		else
		{
			tmp2 = ft_strjoin(tmp, "\n");
			new = ft_strjoin(tmp2, line);
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
		}
		return (new);
	}
	return (line);
}
