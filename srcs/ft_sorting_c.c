/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:50:02 by fguarrac          #+#    #+#             */
/*   Updated: 2019/07/30 15:31:13 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void		ft_if_small(t_link *link_new, t_link *link)
{
	while (link_new->ctspec < link->ctspec && link->next != NULL)
		link = link->next;
	if (link_new->ctspec == link->ctspec)
		while (ft_strcmp_lex(link_new->name, link->name) > 0
				&& link_new->ctspec == link->ctspec
				&& link->next != NULL)
			link = link->next;
	if (link->next == NULL
			&& ft_strcmp_lex(link_new->name, link->name) > 0
			&& link_new->ctspec == link->ctspec)
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
	while (link_new->ctspec == link->ctspec
			&& ft_strcmp_lex(link_new->name, link->name) > 0
			&& link->next != NULL)
		link = link->next;
	if (link->next == NULL
			&& link_new->ctspec == link->ctspec
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
	path = ft_addir(path, name);
	if (stat(path, &link->file_stat) == -1)
	{
		ft_putstr_fd("Error reading file.\n", 2);
		return (NULL);
	}
	link->name = ft_strdup(name);
	link->ctspec = link->file_stat.st_ctimespec.tv_sec;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static void		ft_link_elem(t_link *link_new, t_link **head)
{
	t_link		*link;
	static int	nbr;

	link = *head;
	if (link_new->ctspec < link->ctspec)
		ft_if_small(link_new, link);
	else if (link_new->ctspec > link->ctspec)
	{
		link_new->next = link;
		link->prev = link_new;
	}
	else
		ft_is_equal(link_new, link);
	link->nbr = nbr;
}

t_link			*ft_sorting_c(char *path)
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
