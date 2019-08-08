/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:45:33 by sikenn            #+#    #+#             */
/*   Updated: 2019/06/25 15:53:58 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*s2;

	if (!s1)
		return (NULL);
	l = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * ((ft_strlen(s1)) + 1))))
		return (0);
	l = 0;
	while (s1[l] != '\0')
	{
		s2[l] = s1[l];
		l++;
	}
	s2[l] = 0;
	return (s2);

}
