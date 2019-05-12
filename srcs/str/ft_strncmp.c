/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:46:13 by sikenn            #+#    #+#             */
/*   Updated: 2018/11/26 11:51:44 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t len;

	len = (ft_strlen(s1) <= ft_strlen(s2)) ?
		ft_strlen(s1) + 1 : ft_strlen(s2) + 1;
	len = (len <= n) ? len : n;
	return (ft_memcmp((void *)s1, (void *)s2, len));
}
