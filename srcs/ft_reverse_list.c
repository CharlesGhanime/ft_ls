/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 12:43:59 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/24 18:36:59 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_reverse_list(t_stock **head)
{
	t_stock *previous;
	t_stock *current;
	t_stock *next;

	if (!head)
		return (-1);
	current = *head;
	while (current)
	{
		next = current->next;
		previous = current;
		current = next;
	}
	*head = previous;
	return (0);
}
