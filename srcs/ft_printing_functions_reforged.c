/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_functions_reforged.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:59:45 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/07 20:57:20 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printing_functions.h"
#include "../includes/ft_ls.h"
#include "libft.h"
#include <sys/types.h>

ssize_t		ft_write_from(int fd, const void *buf, int start, size_t len)
{
	int i;

	i = 0;
	while (start > 0)
	{
		buf = (const char *)buf + 1;
		start--;
	}
	return (write(fd, buf, len));
}

void	ft_get_file_name(const char *arg, unsigned int size_name)
{
	size_t i;

	i = 0;
	//ft_putstr_fd("Nom : ", 1);
	ft_putstr_fd(arg, 1);
	//ft_putstr_fd("    ", 1);
	while (i < (size_name - ft_strlen(arg) + 1))
	{
		write(1, " ", 1);
		i++;
	}
}

void	ft_get_file_type(int st_mode)
{   
	//ft_putstr_fd("Type : ", 1);
	if ((st_mode & 0170000) == 0010000)
		ft_putstr_fd("p", 1);
	else if ((st_mode & 0170000) == 0020000)
		ft_putstr_fd("c", 1);
	else if ((st_mode & 0170000) == 0040000)
		ft_putstr_fd("d", 1);
	else if ((st_mode & 0170000) == 0060000)
		ft_putstr_fd("b", 1);
	else if ((st_mode & 0170000) == 0100000)
		ft_putstr_fd("-", 1);
	else if ((st_mode & 0170000) == 0120000)
		ft_putstr_fd("l", 1);
	else if ((st_mode & 0170000) == 0140000)
		ft_putstr_fd("s", 1);
	else if ((st_mode & 0170000) == 0160000)
		ft_putstr_fd("w", 1);
}

void	ft_get_file_major_minor(dev_t st_rdev, unsigned int size_major, unsigned int size_minor)
{
	char *major;
	char *minor;
	size_t i;

	i = 0;
	major = ft_itoa(major(st_rdev));
	minor = ft_itoa(minor(st_rdev));
	while (i < (size_major - ft_strlen(major)))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr_fd(major, 1);
	write (1, ", ", 2);
	i = 0;
	while (i < (size_minor - ft_strlen(minor)))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr_fd(minor, 1);
	write(1, " ", 1);
}

void	ft_get_file_perms(int st_mode)
{
	//ft_putstr_fd("Modes : ", 1);
	ft_get_user_perms(st_mode);
	ft_get_group_perms(st_mode);
	ft_get_other_perms(st_mode);
	ft_putstr_fd("  ", 1);
}

void	ft_get_user_perms(int st_mode)
{
	if ((st_mode & 0004700) == 0000700)
		ft_putstr_fd("rwx", 1);
	if ((st_mode & 0004700) == 0000600)
		ft_putstr_fd("rw-", 1);
	if ((st_mode & 0004700) == 0000500)
		ft_putstr_fd("r-x", 1);
	if ((st_mode & 0004700) == 0000400)
		ft_putstr_fd("r--", 1);
	if ((st_mode & 0004700) == 0000300)
		ft_putstr_fd("-wx", 1);
	if ((st_mode & 0004700) == 0000200)
		ft_putstr_fd("-w-", 1);
	if ((st_mode & 0004700) == 0000100)
		ft_putstr_fd("--x", 1);
	if ((st_mode & 0004700) == 0000000)
		ft_putstr_fd("---", 1);
	if ((st_mode & 0004700) == 0004700)
		ft_putstr_fd("rws", 1);
	if ((st_mode & 0004700) == 0004600)
		ft_putstr_fd("rwS", 1);
	if ((st_mode & 0004700) == 0004500)
		ft_putstr_fd("r-s", 1);
	if ((st_mode & 0004700) == 0004400)
		ft_putstr_fd("r-S", 1);
	if ((st_mode & 0004700) == 0004300)
		ft_putstr_fd("-ws", 1);
	if ((st_mode & 0004700) == 0004200)
		ft_putstr_fd("-wS", 1);
	if ((st_mode & 0004700) == 0004100)
		ft_putstr_fd("--s", 1);
	if ((st_mode & 0004700) == 0004000)
		ft_putstr_fd("--S", 1);
}

void	ft_get_group_perms(int st_mode)
{
	if ((st_mode & 0002070) == 0000070)
		ft_putstr_fd("rwx", 1);
	if ((st_mode & 0002070) == 0000060)
		ft_putstr_fd("rw-", 1);
	if ((st_mode & 0002070) == 0000050)
		ft_putstr_fd("r-x", 1);
	if ((st_mode & 0002070) == 0000040)
		ft_putstr_fd("r--", 1);
	if ((st_mode & 0002070) == 0000030)
		ft_putstr_fd("-wx", 1);
	if ((st_mode & 0002070) == 0000020)
		ft_putstr_fd("-w-", 1);
	if ((st_mode & 0002070) == 0000010)
		ft_putstr_fd("--x", 1);
	if ((st_mode & 0002070) == 0000000)
		ft_putstr_fd("---", 1);
	if ((st_mode & 0002070) == 0002070)
		ft_putstr_fd("rws", 1);
	if ((st_mode & 0002070) == 0002060)
		ft_putstr_fd("rwS", 1);
	if ((st_mode & 0002070) == 0002050)
		ft_putstr_fd("r-s", 1);
	if ((st_mode & 0002070) == 0002040)
		ft_putstr_fd("r-S", 1);
	if ((st_mode & 0002070) == 0002030)
		ft_putstr_fd("-ws", 1);
	if ((st_mode & 0002070) == 0002020)
		ft_putstr_fd("-wS", 1);
	if ((st_mode & 0002070) == 0002010)
		ft_putstr_fd("--s", 1);
	if ((st_mode & 0002070) == 0002000)
		ft_putstr_fd("--S", 1);
}

void	ft_get_other_perms(int st_mode)
{
	if ((st_mode & 0001007) == 0000007)
		ft_putstr_fd("rwx", 1);
	if ((st_mode & 0001007) == 0000006)
		ft_putstr_fd("rw-", 1);
	if ((st_mode & 0001007) == 0000005)
		ft_putstr_fd("r-x", 1);
	if ((st_mode & 0001007) == 0000004)
		ft_putstr_fd("r--", 1);
	if ((st_mode & 0001007) == 0000003)
		ft_putstr_fd("-wx", 1);
	if ((st_mode & 0001007) == 0000002)
		ft_putstr_fd("-w-", 1);
	if ((st_mode & 0001007) == 0000001)
		ft_putstr_fd("--x", 1);
	if ((st_mode & 0001007) == 0000000)
		ft_putstr_fd("---", 1);
	if ((st_mode & 0001007) == 0001006)
		ft_putstr_fd("rwT", 1);
	if ((st_mode & 0001007) == 0001004)
		ft_putstr_fd("r-T", 1);
	if ((st_mode & 0001007) == 0001002)
		ft_putstr_fd("-wT", 1);
	if ((st_mode & 0001007) == 0001000)
		ft_putstr_fd("--T", 1);
	if ((st_mode & 0001007) == 0001007)
		ft_putstr_fd("rwt", 1);
	if ((st_mode & 0001007) == 0001005)
		ft_putstr_fd("r-t", 1);
	if ((st_mode & 0001007) == 0001003)
		ft_putstr_fd("-wt", 1);
	if ((st_mode & 0001007) == 0001001)
		ft_putstr_fd("--t", 1);
}

void	ft_get_file_links(int st_nlink, unsigned int size_links)
{
	char *str;
	size_t i;

	i = 0;
	str = NULL;
	//ft_putstr_fd("Nombre de liens : ", 1);
	str = ft_itoa(st_nlink);
	while (i < (size_links - ft_strlen(str)))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr_fd(str, 1);
	write(1, " ", 1);
	//ft_putstr_fd("    ", 1);
}

void	ft_get_user(char *pw_name, unsigned int size_user)
{
	size_t i;

	i = 0;
	//ft_putstr_fd("Proprietaire : ", 1);
	ft_putstr_fd(pw_name, 1);
	//ft_putstr_fd("    ", 1);
	while (i < (size_user - ft_strlen(pw_name) + 1))
	{
		write(1, " ", 1);
		i++;
	}
}

void	ft_get_group(char *gr_name, unsigned int size_group)
{
	size_t i;

	i = 0;
	//ft_putstr_fd("Groupe : ", 1);
	ft_putstr_fd(gr_name, 1);
	//		ft_putstr_fd("    ", 1);
	while (i < (size_group - ft_strlen(gr_name) + 1))
	{
		write(1, " ", 1);
		i++;
	}
}

void	ft_get_size(off_t st_size, unsigned int size_size)
{
	char    *str;
	size_t i;

	i = 0;
	str = NULL;
	//ft_putstr_fd("Taille : ", 1);
	str = ft_lltoa(st_size);
	while (i < (size_size - ft_strlen(str)))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr_fd(str, 1);
	write(1, " ", 1);
	//ft_putstr_fd(" octets    ", 1);
}

void	ft_get_time_mod(struct timespec st_mtimespec)
{
	char	*time_format;
	int		six_months_before;
	int		six_months_ahead;

	//ft_putstr_fd("Date de derniere modification : ", 1);
	//write(1, ft_itoa(st_mtimespec.tv_sec), 30);
	six_months_before = (time(NULL) - 15778463);
	six_months_ahead = (time(NULL) + 15778463);
	time_format = ctime(&st_mtimespec.tv_sec);
	if (st_mtimespec.tv_sec < six_months_before || st_mtimespec.tv_sec > six_months_ahead)
	{
		ft_write_from(1, time_format, 4, 7);
		write(1, " ", 1);
		write(1, ft_itoa(1970+((st_mtimespec.tv_sec)/(31556926))), 4);
	}
	else
		ft_write_from(1, time_format, 4, 12);
	ft_putstr_fd(" ", 1);
}

/*
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
*/
