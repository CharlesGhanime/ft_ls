/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:32:17 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/07 16:53:05 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;

	unsigned char 	flags;
	int 			i;
	char			*path;
	t_link			*dir;

	path = NULL;
	flags = parsing(ac, av);
	dir = NULL;
	if (g_optind == ac)
	{
		path = ft_strdup(".");
		dispatcher(flags, path, path, dir);
		return (0);
	}
	av = ft_sorting_tabs(av, g_optind, ac);
	av = test_params_dir(g_optind, &ac, av);
	i = 0;
	while (i < ac)
	{
		path = ft_strdup(av[i]);
		if (ac > 1)
			output_path(path);
		dispatcher(flags, path, path, dir);
		i++;
		if (i != ac)
			ft_putchar('\n');
	}
	free_tab_char(av, ac);
	return (0);
}
