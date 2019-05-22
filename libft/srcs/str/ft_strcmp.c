/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:45:17 by sikenn            #+#    #+#             */
/*   Updated: 2018/11/26 11:45:18 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t len;

	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1) + 1;
	else
		len = ft_strlen(s2) + 1;
	return (ft_memcmp((void *)s1, (void *)s2, len));
}
