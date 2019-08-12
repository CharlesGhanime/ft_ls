/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:50:42 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/12 14:17:27 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatcher.h"

int		dispatcher(t_link *dir, char *path, unsigned char flags)
{
/* APPEL DE LA FONCTION QUI OPENDIR PUIS READDIR POUR REMPLIR LA LISTE */

/* SORTING PART */

	if (flags & 1 << 3)
	{
		ft_putendl("Calling r sorting");
		trie_affiche(dir, path, ft_sorting_r);
	}
	if (flags & 1 << 4)
	{
		ft_putendl("Calling t sorting");
		trie_affiche(dir, path, ft_sorting_t);
	}
	if (flags & 1 << 5)
	{
		ft_putendl("Calling u sorting");
		trie_affiche(dir, path, ft_sorting_u);
	}
	if (flags & 1 << 6)
	{
		ft_putendl("Calling f sorting");
		trie_affiche(dir, path, ft_sorting_f);
	}
	if (flags & 1 << 3 && flags & 1 << 4)
	{
		ft_putendl("Calling rt sorting");
		trie_affiche(dir, path, ft_sorting_rt);
	}
	if (!(flags & 1 << 3 && flags & 1 << 4))
	{
		ft_putendl("Calling default sorting");
		trie_affiche(dir, path, ft_sorting_default);
	}
}

/* OUTPUT PART */

	if (flags & 1 << 0)
	{
		ft_putendl("Calling l output");
		trie_affiche(dir, path, ft_output_l);
	}
	if (flags & 1 << 2)
	{
		ft_putendl("Calling a output");
		trie_affiche(dir, path, ft_output_l);
	}
	if (flags & 1 << 0 && flags & 1 << 2)
	{
		ft_putendl("Calling la output");
		trie_affiche(dir, path, ft_output_la);
	}
	if (!(flags & 1 << 0 && flags & 1 << 2))
	{
		ft_putendl("Calling default output");
		trie_affiche(dir, path, ft_output_default);
	}
