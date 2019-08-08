/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:56:04 by sikenn            #+#    #+#             */
/*   Updated: 2019/07/25 13:24:45 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void	scan_dirs_recu(unsigned char flags, char *path, t_link *dir)
{
	while ((ft_strcmp(dir->name, ".") == 0)
			|| ft_strcmp(dir->name, "..") == 0)
	{
		if (dir->next)
			dir = dir->next;
		else
			break ;
	}
	while (dir)
	{
		path = ft_addir(path, dir->name);	
		if (is_regular_file(path))
		{
			path = ft_deldir(path);
		}
		if (is_dir_file(path))
		{
			output_path(path);
			dispatcher(flags, path, NULL);
			ft_deldir(path);
		}
		if (dir->next)
			dir = dir->next;
		else
			break ;
	}
}
