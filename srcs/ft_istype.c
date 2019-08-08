/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:37:13 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/04 17:08:58 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "libft.h"

int		is_regular_file(const char *path)
{
	struct	stat 	sb;

	stat(path, &sb);
	return (S_ISREG(sb.st_mode));
}

int		is_dir_file(char *path)
{
	struct	stat	sb;

	if (path == NULL)
		return (0);
	stat(path, &sb);
	free(path);
	return (S_ISDIR(sb.st_mode));
}

int		is_link_file(const char *path)
{
	struct	stat	sb;
	int				ret;

	if (stat(path, &sb) == -1)
	{
		perror("Error link: ");
	}
	ret = S_ISLNK(sb.st_mode);
	return (ret);
}
