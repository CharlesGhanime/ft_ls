/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_params_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:40:06 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/03 17:25:38 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <stdio.h>

char			**test_params_dir(int index, int *length, char **av)
{
	int		count;
	int		save_index;
	int		i;
	char	**res;
	DIR		*dir;

	count = 0;
	save_index = index;
	while (index < *length)
	{
		if (!(dir = opendir(av[index])))
			count++;
		index++;
		closedir(dir);
	}
	index = save_index;
	if (!(res = (char**)malloc((*length - index - count) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (index < *length)
	{
		if (!(dir = opendir(av[index])))
			error_open_dir(av[index]);
		else
		{
			res[i] = ft_strdup(av[index]);
			i++;
		}
		index++;
		closedir(dir);
	}
	*length = (*length - save_index - count);
	return (res);
}
