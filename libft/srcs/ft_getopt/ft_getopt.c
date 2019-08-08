/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemmou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:21:51 by ichemmou          #+#    #+#             */
/*   Updated: 2019/08/01 14:32:49 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		g_optind = 0;
int		g_optopt = 0;

int		ft_getopt(int ac, char **av, const char *optstring)
{
	static int			i = 0;
	static int			j = 1;

	while (j < ac)
	{
		if ((ft_strcmp(av[j], "-") == 0) || (ft_strcmp(av[j], "--") == 0))	
		{
			g_optind = j + 1;
			return (-1);
		}
		if (av[j][0] != '-')
		{
			g_optind = j;
			return (-1);
		}
		while (av[j][++i] && av[j][0] == '-')
		{
			if (ft_strrchr(optstring, av[j][i]))
				return (av[j][i]);
			else
			{
				g_optopt = av[j][i];
				return ('?');
			}
		}
		i = 0;
		j++;
	}
	g_optind = j;
	return (-1);
}
