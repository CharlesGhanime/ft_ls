/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_t_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:52:37 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/03 08:11:43 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_output_l.h"

t_size	*init_size(t_size *lsize)
{
	lsize->size_links = 0;
	lsize->size_user = 0;
	lsize->size_group = 0;
	lsize->size_major = 0;
	lsize->size_minor = 0;
	lsize->size_size = 0;
	lsize->size_name = 0;
	lsize->next = NULL;
	return (lsize);
}

t_size	alloc_size(t_size *lsize)
{
	
}

t_size	*add_size(t_size *lsize)
{
	if (!lsize)
		ft_struct_t_size_init(lsize);
	lsize = (t_size)malloc(sizeof(t_size))
}
