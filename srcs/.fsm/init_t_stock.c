/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_stock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:33:51 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/17 19:09:12 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_stock		*init_head(t_stock *head)
{
	t_stock *stock;

	head = NULL;
	if (!(stock = (t_stock *)malloc(sizeof(t_stock))))
		return (0);
	stock->flag = 0;
	stock->path = 0;
	stock->dir = NULL;
	stock->filer = NULL;
	stock->buff = NULL;
	return (stock);
}


