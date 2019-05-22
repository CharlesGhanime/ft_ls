/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemmou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:21:51 by ichemmou          #+#    #+#             */
/*   Updated: 2019/05/12 16:27:39 by ichemmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_getopt(int ac, char **av, char *optstring)
{
	static int	i = 1;
	static int	j = 1;
	int tmp;

	if (ac > 1)
	{
		if (av[j][0] == '-' && av[j][1] == '-' && av[j][2] == '\0')
			return ('?');
		if (av[j][0] && j < ac - 1 && av[j][0] != '-')
		{
			j++;
			return (0);
		}
		if (av[j][i] && av[j][i] != '\0' && ft_strchr(optstring, av[j][i]))
		{
			if (av[j][i + 1] && av[j][i + 1] == '\0')
			{
				j++;
				tmp = i;
				i = 1;
				return (av[j - 1][tmp]);
			}
			else
				i++;
			return (av[j][i - 1]);
		}
		else if (ft_strchr(optstring, av[j][i]) == NULL)
		{
			if (av[j][i + 1] && av[j][i + 1] == '\0')
			{
				j++;
				tmp = i;
				i = 1;
				return ('?');
			}
			else
			{
				i++;
				return ('?');
			}
		}
		else
			return (-1);
	}
	return (-1);
}
