/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:55:01 by fguarrac          #+#    #+#             */
/*   Updated: 2019/08/07 13:43:29 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static t_link	*ft_make_link(char *path, char *name)
{
	t_link			*link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	path = ft_addir(path, name);
	if (lstat(path, &link->file_stat) == -1)
	{
		ft_putstr_fd("Error reading file.\n", 2);
		return (NULL);
	}
	free(path);
	link->name = ft_strdup(name);
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static void		ft_link_elem(t_link *link_new, t_link **head)
{
	t_link		*cursor;

	if (*head == NULL)
	{
		*head = link_new;
		return ;
	}
	cursor = *head;
	while (cursor->next && (ft_strcmp(link_new->name, cursor->name) > 0))
		cursor = cursor->next;
	if (ft_strcmp(link_new->name, cursor->name) <= 0)
	{
		link_new->next = cursor;
		link_new->prev = cursor->prev;
		if (cursor->prev)
			cursor->prev->next = link_new;
		cursor->prev = link_new;
	}
	else
	{
		cursor->next = link_new;
		link_new->prev = cursor;
	}
}

t_link			*ft_sorting(char *path)
{
	t_link			*head;
	t_link			*link_new;
	DIR				*dir;
	struct dirent	*file;

	dir = opendir(path);
	head = NULL;
	while ((file = readdir(dir)))
	{
		link_new = ft_make_link(path, file->d_name);
		ft_link_elem(link_new, &head);
		link_new->namelen = file->d_namlen;
		while (link_new->prev)
			link_new = link_new->prev;
	}
	closedir(dir);
	ft_num_list(head);
	return (head);
}
