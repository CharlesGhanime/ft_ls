/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_t.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:55:01 by fguarrac          #+#    #+#             */
/*   Updated: 2019/07/30 15:32:42 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void		ft_if_small(t_link *link_new, t_link *link)
{
	while (link_new->mtspec < link->mtspec && link->next != NULL)
		link = link->next;
	if (link_new->mtspec == link->mtspec)
		while (ft_strcmp_lex(link_new->name, link->name) > 0
				&& link_new->mtspec == link->mtspec
				&& link->next != NULL)
			link = link->next;
	if (link->next == NULL
			&& ft_strcmp_lex(link_new->name, link->name) > 0
			&& link_new->mtspec == link->mtspec)
	{
		link->next = link_new;
		link_new->prev = link;
	}
	link_new->next = link;
	link_new->prev = link->prev;
	if (link->prev != NULL)
		link->prev->next = link_new;
	link->prev = link_new;
}

static void		ft_is_equal(t_link *link_new, t_link *link)
{
	while (link_new->mtspec == link->mtspec
			&& ft_strcmp_lex(link_new->name, link->name) > 0
			&& link->next != NULL)
		link = link->next;
	if (link->next == NULL
			&& link_new->mtspec == link->mtspec
			&& ft_strcmp_lex(link_new->name, link->name) > 0)
	{
		link->next = link_new;
		link_new->prev = link;
	}
	link_new->next = link;
	link_new->prev = link->prev;
	if (link->prev != NULL)
		link->prev->next = link_new;
	link->prev = link_new;
}

static t_link	*ft_make_link(char *name, char *path)
{
	t_link			*link;

	if (!(link = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	if (name)
	{
		path = ft_addir(path, name);
		if (stat(path, &link->file_stat) == -1)
		{
			ft_putstr_fd("Error reading file.\n", 2);
			return (NULL);
		}
		link->mtspec = link->file_stat.st_mtimespec.tv_sec;
	}
	link->name = ft_strdup(name);
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static void		ft_link_elem(t_link *link_new, t_link **head)
{
	t_link		*link;
	static int	nbr;

	link = *head;
	if (link_new->mtspec < link->mtspec)
		ft_if_small(link_new, link);
	else if (link_new->mtspec > link->mtspec)
	{
		link_new->next = link;
		link->prev = link_new;
	}
	else
		ft_is_equal(link_new, link);
	link->nbr = nbr;
}

t_link			*ft_sorting_t(char *path)
{
	t_link			*head;
	t_link			*link;
	t_link			*link_new;
	DIR				*dir;
	struct dirent	*file;

	if (!(dir = opendir(path)))
	{
		ft_putstr_fd("Error opening dir.\n", 2);
		return (NULL);
	}
	link = ft_make_link(NULL, NULL);
	head = link;
	while ((file = readdir(dir)))
	{
		link_new = ft_make_link(file->d_name, path);
		if (head == NULL)
			head = link_new;
		ft_link_elem(link_new, &head);
		while (link->prev != NULL)
			link = link->prev;
		head = link;
		link_new->namelen = file->d_namlen;
	}
	closedir(dir);
	ft_num_list(head);
	return (head);
}
