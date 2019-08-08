/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:40:28 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/04 19:24:22 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

/*
**
**	Please guys, think of the order of the events in our ft_ls...
**	This order is defined by the lines in the dispatcher...
**
**	For example : It is not possible to call function -l before any other
**					sort function.
**					Or calling -R before a printing function.
**
**	So, if you need to modify dispatcher.c, think of keeping it logic!
**
*/

void		dispatcher(unsigned char flags, char *path, char *target, t_link *dir)
{

// SORTING PART

	if (flags & 1 << 0 && flags & 1 << 2)
		ft_putendl("Calling a and l");
	if (flags & 1 << 3)
		ft_putendl("Calling r");
	if (flags & 1 << 4)			// call function t
		dir = ft_sorting_t(path);
	if (flags & 1 << 5 )			// call function u
		dir = ft_sorting_u(path);
	if (flags & 1 << 6)			// call function f
		dir = ft_sorting_f(path);
	if (flags & 1 << 3 && flags & 1 << 4)
		ft_putendl("Calling t and r");
	if (!(flags & 1 << 3) && !(flags & 1 << 4))
	{
		dir = ft_sorting(path);
	}

// LIST NUMBERING PART

	ft_num_list(dir);

// OUTPUT PART
	if (flags & 1 << 0)
	{
			ft_print_l(dir, path);
	}
	if (flags & 1 << 2)
		basic_output_a(dir);
	if (!(flags & 1 << 0) && !(flags & 1 << 2))
		basic_output(dir);
	if (flags & 1 << 1)
	{
		scan_dirs_recu(flags, path, target, dir);
	}
	else
		free(path);
	free_list(dir);
}
/*********/
/* BONUS */
/*********/

/*
** if (flags & 1 << 5 )
**      call function u
** if (flags & 1 << 6)
**      call function f
** if (flags & 1 << 7)
**      call function g
** if (flags & 1 << )
**      call function uu // ls -U
** if (flags & 1 << )
**      call function F
** if (flags & 1 << )
**      call function c
*/
