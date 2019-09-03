/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_other_perms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 04:09:58 by cghanime          #+#    #+#             */
/*   Updated: 2019/09/02 04:12:35 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../includes/ft_ls.h"
#include "libft.h"
#include <sys/types.h>

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
}

void	ft_get_other_perms_2(int st_mode)
{
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
