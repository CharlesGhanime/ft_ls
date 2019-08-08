/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:43:48 by fguarrac          #+#    #+#             */
/*   Updated: 2019/07/30 15:32:07 by fguarrac         ###   ########.fr       */
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
	if (stat(path, &link->file_stat) == -1)
	{
		ft_putstr_fd("Error reading file.\n", 2);
		return (NULL);
	}
	link->name = ft_strdup(name);
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static void		ft_link_elem(t_link *link_new, t_link **head)
{
	t_link			*link;

	link = *head;
	while (link->next != NULL)
		link = link->next;
	link->next = link_new;
	link_new->prev = link;
	link_new->next = NULL;
}

t_link			*ft_sorting_f(char *path)
{
	t_link			*head;
	t_link			*link_new;
	DIR				*dir;
	struct dirent	*file;

	if (!(dir = opendir(path)))
	{
		ft_putstr_fd("Error opening dir.\n", 2);
		return (NULL);
	}
	while ((file = readdir(dir)))
	{
		link_new = ft_make_link(path, file->d_name);
		head = link_new;
		ft_link_elem(link_new, &head);
		link_new->namelen = file->d_namlen;
	}
	closedir(dir);
	ft_num_list(head);
	return (head);
}
