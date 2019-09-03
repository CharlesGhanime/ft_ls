/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 04:14:54 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/02 04:15:36 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "libft.h"
#include <sys/types.h>

int		main(int argc, char **argv)
{
	struct stat     file_stats;
	struct  passwd   *user_passwd;
	struct group    *group_passwd;
	unsigned int size_links = 2, size_user = 10, size_group = 12, size_size = 3, size_name = 30;
	unsigned int i = 1;

	if (argc < 2)
	{
		ft_putstr_fd("Error. Usage : ft_inspect_file [file name]\n", 2);
		return (-1);
	}
	while (i < argc)
	{
		if (stat(argv[i], &file_stats) == -1)
		{
			ft_putstr_fd("Error reading file.\n", 2);
			return (-1);
		}
		if ((user_passwd = getpwuid(file_stats.st_uid)) == NULL)
		{
			ft_putstr_fd(ft_itoa(file_stats.st_uid), 1);
		}
		if ((group_passwd = getgrgid(file_stats.st_gid)) == NULL)
		{
			ft_putstr_fd(ft_itoa(file_stats.st_gid), 1);
		}
		ft_get_file_type(file_stats.st_mode);
		ft_get_file_perms(file_stats.st_mode);
		ft_get_file_links(file_stats.st_nlink, size_links);
		ft_get_user(user_passwd->pw_name, size_user);
		ft_get_group(group_passwd->gr_name, size_group);
		ft_get_size(file_stats.st_size, size_size);
		ft_get_time_mod(file_stats.st_mtimespec);
		ft_get_file_name(argv[i], size_name);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
