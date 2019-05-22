/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:42:43 by sikenn            #+#    #+#             */
/*   Updated: 2019/01/22 17:11:40 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnewf(void *content, size_t content_size)
{
	t_list *new;

	new = ft_lstnew(content, content_size);
	free(content);
	return (new);
}
