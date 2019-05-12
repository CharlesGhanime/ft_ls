/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemmou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:21:51 by ichemmou          #+#    #+#             */
/*   Updated: 2019/05/12 16:02:58 by ichemmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_getopt(int ac, char **av, char *optstring)
{
	static int	i = 1;
	static int	j = 1;

	if (ac > 1)
	{
		if (j >= ac)
			return (-1);
		if (av[j][0] && j < ac - 1 && av[j][0] != '-')
		{
			j++;
			return (0);
		}
		if (av[j][i] && ft_strchr(optstring, av[j][i]))
		{
			if (av[j][i + 1] != '\0')
				i++;
			else
			{
				j++;
				i = 1;
			}
			return (av[j][i]);
		}
	}
	return (-1);
}
