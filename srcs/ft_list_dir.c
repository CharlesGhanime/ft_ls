/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:13:03 by sikenn            #+#    #+#             */
/*   Updated: 2019/05/29 15:50:55 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int     ft_list_dir(char *dir)
{
    DIR *res;
    struct dirent *obj;

    if (!(res = opendir(dir)))
    {
        perror("Error: "); 
        exit(0);
    }
    while ((obj = readdir(res)))
    {
        ft_putendl(obj->d_name);
    }
    if (closedir(res) == 0)
        return (1);
    return (-1);
}
