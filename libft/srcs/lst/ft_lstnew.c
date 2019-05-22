/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:58:40 by sikenn            #+#    #+#             */
/*   Updated: 2019/01/22 17:18:31 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*data;

	if (!(data = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		data->content = NULL;
		data->content_size = 0;
	}
	else
	{
		if (!(data->content = (void *)malloc(content_size)))
		{
			free(data);
			return (NULL);
		}
		ft_memcpy(data->content, content, content_size);
		data->content_size = content_size;
	}
	data->next = NULL;
	return (data);
}
