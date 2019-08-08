/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:13:03 by sikenn            #+#    #+#             */
/*   Updated: 2019/06/26 15:03:52 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_ls.h"
#include "libft.h"

int     ft_list_dir(char *dir)
{
    DIR				*res;
    struct dirent	*obj;

    if (!(res = opendir(dir)))
    {
        perror("Error opendir: "); 
        exit(0);
    }
    while ((obj = readdir(res)))
    {
		if (obj->d_name[0] != '.')
		{
        	ft_putstr(obj->d_name);
			ft_putchar(' ');
			if (is_regular_file(obj->d_name))
			{
        		ft_putstr(obj->d_name);
				ft_putchar(' ');
			}
			if (is_dir_file(obj->d_name))
			{
				ft_putstr("\x1B[32m");
  	     		ft_putstr(obj->d_name);
        		ft_putstr("\x1B[0m");
				ft_putchar(' ');
			}
		}
    }
    if (closedir(res) == 0)
        return (1);
    return (-1);
}
