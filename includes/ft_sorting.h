/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:01:54 by fguarrac          #+#    #+#             */
/*   Updated: 2019/08/04 19:29:34 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORTING_H
# define FT_SORTING_H

# include <dirent.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_link
{
	char			*name;
	int				nbr;
	int				namelen;
	time_t			mtspec;
	time_t			ctspec;
	time_t			atspec;
	time_t			btspec;
	struct s_link	*next;
	struct s_link	*prev;
	struct stat		file_stat;
}				t_link;

t_link			*ft_sorting(char *path);
t_link			*ft_sorting_t(char *path);
t_link			*ft_sorting_c(char *path);
t_link			*ft_sorting_f(char *path);
t_link			*ft_sorting_u(char *path);
t_link			*ft_sorting_uu(char *path);
char			**test_params_dir(int index, int *length, char **av);

#endif
