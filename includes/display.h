/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:26:08 by sikenn            #+#    #+#             */
/*   Updated: 2019/07/30 20:06:19 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <sys/ioctl.h>

typedef struct		s_out
{   
	struct winsize  w;
	int             elem;
	int             j;
	int             k;
	int             c;
	int             r;
	int             **tab;
	char            *space;
	int		len;
	t_link          *tmp;
}					t_out;

void    usage(const char *usage, char illegal);
void	error_open_dir(char *dir);
void	basic_output(t_link *dir);
void	basic_output_a(t_link *dir);
void	ft_output_a(t_link *dir);
void	output_path(char *path);

#endif
