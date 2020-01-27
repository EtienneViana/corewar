/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:16:43 by eviana            #+#    #+#             */
/*   Updated: 2019/03/18 17:39:08 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*st_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char*)&haystack[i + j + 1]);
			j++;
		}
		i++;
	}
	return (NULL);
}

static char		*st_choose_color(char *str)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strstr(str, "{red}");
	if (((tmp2 = ft_strstr(str, "{green}")) && tmp2 < tmp) || tmp == NULL)
		tmp = tmp2;
	if (((tmp2 = ft_strstr(str, "{yellow}")) && tmp2 < tmp) || tmp == NULL)
		tmp = tmp2;
	if (((tmp2 = ft_strstr(str, "{blue}")) && tmp2 < tmp) || tmp == NULL)
		tmp = tmp2;
	if (((tmp2 = ft_strstr(str, "{purple}")) && tmp2 < tmp) || tmp == NULL)
		tmp = tmp2;
	if (((tmp2 = ft_strstr(str, "{cyan}")) && tmp2 < tmp) || tmp == NULL)
		tmp = tmp2;
	if (((tmp2 = ft_strstr(str, "{magenta}")) && tmp2 < tmp) || tmp == NULL)
		tmp = tmp2;
	if (((tmp2 = ft_strstr(str, "{eoc}")) && tmp2 < tmp) || tmp == NULL)
		tmp = tmp2;
	return (tmp);
}

static size_t	st_apply_color(char *str)
{
	char	*str2;
	char	*tmp;
	size_t	n;

	if (!(str2 = ft_strsub(str, 0, 9)))
		return (0);
	if ((tmp = st_strstr(str2, "{red}")))
		write(1, "\033[0;31m", 7);
	else if ((tmp = st_strstr(str2, "{green}")))
		write(1, "\033[0;32m", 7);
	else if ((tmp = st_strstr(str2, "{yellow}")))
		write(1, "\033[0;33m", 7);
	else if ((tmp = st_strstr(str2, "{blue}")))
		write(1, "\033[0;34m", 7);
	else if ((tmp = st_strstr(str2, "{purple}")))
		write(1, "\033[0;35m", 7);
	else if ((tmp = st_strstr(str2, "{cyan}")))
		write(1, "\033[0;36m", 7);
	else if ((tmp = st_strstr(str2, "{magenta}")))
		write(1, "\033[0;35;1m", 9);
	else if ((tmp = st_strstr(str2, "{eoc}")))
		write(1, "\033[0m", 4);
	n = ft_strlen(str2) - ft_strlen(tmp);
	free(str2);
	return (n);
}

char			*ft_noconv(t_asset asset, va_list ap)
{
	char	*str;
	char	*str2;
	char	*str3;
	size_t	n;

	str = asset.copy;
	if (!str || str[0] == '%')
		return (ft_strnew(0));
	while ((str2 = st_choose_color(str)))
	{
		if (!(str3 = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(str2))))
			return (NULL);
		ft_fill_buff(str3, 0);
		ft_fill_buff("", 1);
		if (!(n = st_apply_color(str2)))
			return (NULL);
		str = ft_strlen(str) - ft_strlen(str2) + str + n;
		free(str3);
	}
	free(str2);
	(void)ap;
	return (str = ft_strsub(str, 0, ft_strlen(str)));
}
