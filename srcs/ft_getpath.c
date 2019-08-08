/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:39:45 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/04 19:17:35 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char		*init_path(char *name)
{
	char *path;

	if (ft_strcmp(name, ".") == 0)
	{
		if (!(path = (char *)malloc(3 * sizeof(char))))
			return (NULL);
		path = ft_strjoin(name, "/");
		return (path);
	}
	else if (ft_strcmp(name, "./") == 0)
	{
		return (name);
	}
	else
	{
		if (!(path = (char *)malloc((3 + ft_strlen(name)) * sizeof(char))))
			return (NULL);
		return (ft_strjoin("./", name));
	}
} 

/*
static char	*ft_strjoinff(char **s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = (char *)malloc(((ft_strlen(*s1) +
			ft_strlen(s2) + 1)) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*s1[i] != '\0')
	{
		str[i] = *s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(&s1);
	return (str);
}
*/
/*
char	*ft_addir(char *path, char *dir)
{
	path = ft_strjoin(path, "/"); 
	path = ft_strjoin(path, dir); 
	return (path);
}
*/

char	*ft_testddir(char *path, char *dir)
{
	char *res;

	res = ft_strnew(ft_strlen(path) + ft_strlen(dir) + 1);
	ft_strcat(res, path);
	ft_strcat(res, "/");
	ft_strcat(res, dir);
	return (res);
}

// TO DELETE
char	*ft_adddir(char *path, char *dir)
{
	char *res;
	res = ft_strnew(ft_strlen(path) + ft_strlen(dir) + 1);
	ft_strcat(res, path);
	ft_strcat(res, "/");
	ft_strcat(res, dir);
	return (res);
}

char	*ft_addir(char *path, char *dir)
{
	char *res;
	res = ft_strnew(ft_strlen(path) + ft_strlen(dir) + 1);
	ft_strcat(res, path);
	ft_strcat(res, "/");
	ft_strcat(res, dir);
	return (res);
}
/*
char	*ft_addir(char *path, char *dir)
{
	char *res;
	res = ft_strnew(ft_strlen(path) + ft_strlen(dir) + 1);
	ft_strcat(res, path);
	ft_strcat(res, "/");
	ft_strcat(res, dir);
	free(path);
	return (res);
}
*/
/*
char	*ft_deldir(char *path) 
{
	int 	i;
	int		j;
	int		nb;
	char 	*res;

	if (ft_strcmp(path, "./") == 0)
		return (".");
	path = ft_strrev(path);
	i = 0;
	nb = 0;
	while (path[i] != '\0')
	{
		if (path[i] == '/')
			nb++;
		i++;
	}
	i = 0;
	while (path[i] != '/')
		i++;
	if (!(res = (char *)malloc((ft_strlen(path) - i + 1) * sizeof(char))))
		return (NULL);
	if (nb != 1)
		i += 1;
	j = 0;
	while (path[i] != '\0')
	{
		res[j] = path[i];
		i++;
		j++;
	}
	res[j] = '\0';
	res = ft_strrev(res);
	free(path);
	return (res);
}
*/
char	*ft_deldir(char *path)
{
	int curs;
	int i;

	i = 0;
	while (path[i] != '\0')
	{
		if (path[i] == '/')
		{
			curs = i;
		}
		i++;
	}
	while (path[curs] != '\0')
	{
		path[curs] = 0;
		curs++;
	}
	return (path);
}
