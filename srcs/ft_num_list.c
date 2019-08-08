/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:24:59 by fguarrac          #+#    #+#             */
/*   Updated: 2019/07/30 15:27:15 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_num_list(t_link *list)
{
	int nbr;

	nbr = 0;
	while (list->next)
	{
		if (list->name)
		{
			list->nbr = nbr;
			nbr++;
		}
		list= list->next;
	}
}
