/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:55:18 by sikenn            #+#    #+#             */
/*   Updated: 2019/06/25 15:24:01 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <uuid/uuid.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int     ft_inspect_file(char *path)
{
    struct stat sb;
    struct passwd *uid;
    struct group *grp;

    if (stat(path, &sb) == -1)
    {
        perror("Error: ");
        exit(0); 
    }
	ft_putstr("Inode: ");
	ft_putnbr(sb.st_ino);
    ft_putstr("\nType: ");
    if (S_ISDIR(sb.st_mode)) 
        ft_putendl("Directory");
    if (S_ISREG(sb.st_mode)) 
        ft_putendl("File");
    ft_putstr("Modes: ");
    ft_putstr((sb.st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr((sb.st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr((sb.st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr((sb.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr((sb.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr((sb.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr((sb.st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr((sb.st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr((sb.st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr("\nNumbers of links: ");
    ft_putnbr(sb.st_nlink);
    ft_putstr("\nOwner: ");
    uid = getpwuid(sb.st_uid);
    ft_putstr(uid->pw_name);
    grp = getgrgid(sb.st_gid);
    ft_putstr("\nGroup: ");
    ft_putstr(grp->gr_name);
    ft_putstr("\nTaille: ");
    ft_putnbr(sb.st_size);
    ft_putendl(" octet");
    ft_putstr("Last modification time: ");
    ft_putstr(ctime(&sb.st_mtime));
    return (1);
}
