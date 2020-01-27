/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:30:32 by eviana            #+#    #+#             */
/*   Updated: 2018/11/28 21:56:21 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlst;

	if (!(newlst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(newlst->content = (void*)malloc(content_size)))
		{
			free(newlst);
			return (NULL);
		}
		ft_memcpy(newlst->content, content, content_size);
		newlst->content_size = content_size;
	}
	else
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	newlst->next = NULL;
	return (newlst);
}
