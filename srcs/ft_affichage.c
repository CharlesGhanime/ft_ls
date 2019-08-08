/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:20:17 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/08 20:01:02 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/ft_printing_functions.h"
#include "../libft/includes/libft.h"
#include <limits.h>
#include <sys/types.h>

/* -l : 
 *  * permissions d'acces : 10 + 1, 
 *   * liens : taille du plus grands + 1
 *    * login : plus grand + 1, 
 *     * groupe  : plus grand + 1, 
 *      * taille en octets : plus grande + 1,
 *       * horodatage : 12 + 1
 *        */
/*
 * int	ft_affichage(char *path,  )
 * {
 *	if (!buff)
 *			return (1);
 *			}
 *			*/

//# define BUFF_LINK 4096

void	ft_print_l(t_link *dir, char *path)
{
	struct passwd		*user;
	struct group		*group;
//	struct timespec		st_mtimespec;
//	unsigned int		size_perms;
	unsigned int		size_major;
	unsigned int		size_minor;
	unsigned int		size_links;
	unsigned int		size_user;
	unsigned int		size_group;
	unsigned int		size_size;
	unsigned int		size_name;
//	unsigned int		size_timemod;
	t_link				*head;
	char				buff[PATH_MAX];
	long nreadlink = 0;

	size_links = 0;
	size_major = 0;
	size_minor = 0;
	size_user = 0;
	size_group = 0;
	size_size = 0;
	size_name = 0;
	head = dir;

	//buff = NULL;
	user = getpwuid(dir->file_stat.st_uid);
	group = getgrgid(dir->file_stat.st_gid);
	ft_memset(buff, '\0', PATH_MAX);

	while (dir)
	{
//		if (size_perms < ft_strlen(dir->file_stat->st_mode))
//			size_perms = ft_strlen(dir->file_stat->st_mode);
		if (size_major < ft_strlen(ft_itoa(major(dir->file_stat.st_rdev))))
			size_major = ft_strlen(ft_itoa(major(dir->file_stat.st_rdev)));
		if (size_minor < ft_strlen(ft_itoa(minor(dir->file_stat.st_rdev))))
			size_minor = ft_strlen(ft_itoa(minor(dir->file_stat.st_rdev)));
		if (size_links < ft_strlen(ft_itoa(dir->file_stat.st_nlink)))
			size_links = ft_strlen(ft_itoa(dir->file_stat.st_nlink));
		if (size_user < ft_strlen(user->pw_name))
			size_user = ft_strlen(user->pw_name);
		if (size_group < ft_strlen(group->gr_name))
			size_group = ft_strlen(group->gr_name);
		if (size_size < ft_strlen(ft_itoa((dir->file_stat.st_size))))
			size_size = ft_strlen(ft_itoa((dir->file_stat.st_size)));
//		if (size_timemod < ft_strlen(dir->file_stat->st_mtimespec))
//			size_timemod = ft_strlen(dir->file_stat->st_mtimespec);
		if (size_name < ft_strlen(dir->name))
			size_name = ft_strlen(dir->name);
		dir = dir->next;
	}
	dir = head;
	while (dir)
	{
		if (dir->name[0] != '.')
		{
			ft_get_file_type(dir->file_stat.st_mode);
			//if ((dir->file_stat.st_mode & 0170000) == 0120000)
/*			if (S_ISLNK(dir->file_stat.st_mode))
			{
				path = ft_addir(path, dir->name);
				nreadlink = readlink(path, buff, PATH_MAX);
				printf("%s\n%ld\n", buff,  nreadlink);
				path = ft_deldir(path);
			} */
			ft_get_file_perms(dir->file_stat.st_mode);
			ft_get_file_links(dir->file_stat.st_nlink, size_links + 1);
			ft_get_user(user->pw_name, size_user + 2);
			ft_get_group(group->gr_name, size_group + 2);
			if (S_ISCHR(dir->file_stat.st_mode) || S_ISBLK(dir->file_stat.st_mode))
			{
				ft_get_file_major_minor(dir->file_stat.st_rdev, size_major, size_minor);
			}
/*			else if (!(S_ISCHR(dir->file_stat.st_mode)
			|| S_ISBLK(dir->file_stat.st_mode)) && size_major && size_minor)
				ft_get_size(dir->file_stat.st_size, size_major + size_minor + 2);
*/			else
			{
				if (size_major > 1 && size_minor > 1)
					ft_get_size(dir->file_stat.st_size, size_major + size_minor + 2);
				else
					ft_get_size(dir->file_stat.st_size, size_size + 1);
			}
				ft_get_time_mod(dir->file_stat.st_mtimespec);
			if (S_ISLNK(dir->file_stat.st_mode))
				ft_get_file_name(dir->name, ft_strlen(dir->name));
			else
				ft_get_file_name(dir->name, size_name);
			if (S_ISLNK(dir->file_stat.st_mode))
			{
				path = ft_addir(path, dir->name);
				nreadlink = readlink(path, buff, PATH_MAX);
				write(1, "-> ", 4);
				ft_putstr_fd(buff, 1);
				ft_deldir(path);
/*				free_tab_char(&path, PATH_MAX);
				free(buff);*/
			}
			ft_putstr("\n");
		}
/*		if (!dir)
		{
			free_list(dir);
			free_list(head);
		}
		else*/
			dir = dir->next;
	}
}
