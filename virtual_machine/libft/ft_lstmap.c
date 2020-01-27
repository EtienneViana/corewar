/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:17:01 by eviana            #+#    #+#             */
/*   Updated: 2018/12/01 15:09:59 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flst;
	t_list	*newlst;

	if (lst && f)
	{
		newlst = f(lst);
		flst = newlst;
		while (lst->next)
		{
			lst = lst->next;
			if (!(newlst->next = ft_lstnew(f(lst)->content,
							f(lst)->content_size)))
				return (NULL);
			newlst = newlst->next;
		}
		return (flst);
	}
	return (NULL);
}
