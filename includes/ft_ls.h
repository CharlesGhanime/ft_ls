/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 21:13:01 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/03 15:48:54 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <pwd.h>
#include <grp.h>
#include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <errno.h>
# include "parsing.h"
# include "ft_sorting.h"
# include "display.h"
# include "ft_istype.h"
# include "ft_getpath.h"
# include "recursive.h"
# include "dispatcher.h"
# include "free_mem.h"
# define PARAMS "lRartufg"

void	ft_print_l(t_link *dir, char *path);

#endif
