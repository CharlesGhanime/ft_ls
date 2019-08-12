/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:51:11 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/12 13:44:35 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DISPATCHER_H
# define DISPATCHER_H
#include "libft.h"

typedef int (*fptr) (t_link *, char *)

int		dispatcher(t_link *dir, char *path, unsigned char flags);
int		trie_affiche(t_link *dir, char *path, int (&fptr)(t_link *, char *))

# endif
