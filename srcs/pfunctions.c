/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_functions_reforged.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:59:45 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/02 18:25:05 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putstr_fd(arg, 1);
	while (i < (size_name - ft_strlen(arg) + 1))
	{
		write(1, " ", 1);
		i++;
	}
}

void	ft_get_file_type(int st_mode)
{
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
