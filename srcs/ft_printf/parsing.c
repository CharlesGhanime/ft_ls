/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:57:45 by sikenn            #+#    #+#             */
/*   Updated: 2019/03/06 12:17:49 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			verif_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == '%')
		return (1);
	return (0);
}

#include <stdio.h>

t_list		*parsing(char *str)
{
	t_list	*form;
	int 	i;	
	int		start;
	
	i = 0;
	start = 0;
	form = NULL;
	while (str[i] != '\0') 
	{
		while (str[i] != '%')
			i++;
		
		if (str[i] == '%')
		{
			printf("ONE NIGHT STORY\n");
		}
		i++;
	}
	return (form);
}
