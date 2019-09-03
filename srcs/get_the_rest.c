/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_the_rest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 04:14:03 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/02 04:14:33 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "libft.h"
#include <sys/types.h>

void	ft_get_file_links(int st_nlink, unsigned int size_links)
{
	char *str;
	size_t i;

	i = 0;
	str = NULL;
	str = ft_itoa(st_nlink);
	while (i < (size_links - ft_strlen(str)))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr_fd(str, 1);
	write(1, " ", 1);
}

void	ft_get_user(char *pw_name, unsigned int size_user)
{
	size_t i;

	i = 0;
	ft_putstr_fd(pw_name, 1);
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
	ft_putstr_fd(gr_name, 1);
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
	str = ft_lltoa(st_size);
	while (i < (size_size - ft_strlen(str)))
	{
		write(1, " ", 1);
		i++;
	}
	ft_putstr_fd(str, 1);
	write(1, " ", 1);
}

void	ft_get_time_mod(struct timespec st_mtimespec)
{
	char	*time_format;
	int		six_months_before;
	int		six_months_ahead;

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
