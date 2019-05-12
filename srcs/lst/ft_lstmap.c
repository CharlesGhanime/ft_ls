/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:58:36 by sikenn            #+#    #+#             */
/*   Updated: 2018/11/26 16:32:05 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *tmp;
	t_list *begin;

	newlst = NULL;
	tmp = (*f)(lst);
	if (!(newlst = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin = newlst;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!(newlst->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (begin);
}
