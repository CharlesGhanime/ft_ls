/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fet_get_ug_perms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 04:04:29 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/02 04:15:51 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "libft.h"
#include <sys/types.h>

void	ft_get_file_perms(int st_mode)
{
	ft_get_user_perms(st_mode);
	ft_get_user_perms_2(st_mode);
	ft_get_group_perms(st_mode);
	ft_get_group_perms(st_mode);
	ft_get_other_perms_2(st_mode);
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
}

void	ft_get_user_perms_2(int st_mode)
{
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
}

void	ft_group_perms_2(int st_mode)
{
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
