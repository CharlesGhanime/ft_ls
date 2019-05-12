/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:58:35 by sikenn            #+#    #+#             */
/*   Updated: 2018/11/26 16:33:31 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *d;

	if (len == 0)
		return (b);
	d = (unsigned char*)b;
	while (len--)
	{
		*d = (unsigned char)c;
		if (len)
			d++;
	}
	return (b);
}
