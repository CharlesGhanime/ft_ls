/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:56:04 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/04 21:05:33 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"


void	scan_dirs_recu(unsigned char flags, char *path, char *target, t_link *dir)
{
	char	*tmp;

	while (dir->next && ((dir->name[0] == '.' && !dir->name[1]) || (dir->name[0] == '.'  && dir->name[1] == '.' && !dir->name[2])))
		dir = dir->next;
	while (dir->next)
	{
		if (is_dir_file(ft_addir(path, dir->name)))
		{
			ft_putchar('\n');
			tmp = ft_addir(path, dir->name);
			output_path(tmp);
			free(tmp);
			dispatcher(flags, ft_addir(path, dir->name), target, NULL);
		}
		dir = dir->next;
	}
	free(path);
}
