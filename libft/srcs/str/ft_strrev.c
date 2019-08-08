/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:47:03 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/04 15:31:12 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strrev(char *str)
{
	char	*res;
	char	*out;
	int		i;
	
	if (!(res = (char *)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	out = res;
	i = ft_strlen(str);
	out[i] = '\0';
	while (i != 0)
	{
		*out = str[i - 1];
		out++;
		i--;
	}
	free(str);
	return (res);
}
