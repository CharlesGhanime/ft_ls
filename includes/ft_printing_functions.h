/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_functions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:26:59 by cghanime          #+#    #+#             */
/*   Updated: 2019/08/07 20:21:32 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTING_FUNCTIONS
#define FT_PRINTING_FUNCTIONS

#include <unistd.h>
#include <stdio.h>
#include <../libft/includes/conv.h>
#include <../libft/includes/put.h>
#include "ft_ls.h"

ssize_t		ft_write_from(int fd, const void *buf, int start, size_t len);
void		ft_get_file_name(const char *arg, unsigned int size_name);
void		ft_get_file_type(int st_mode);
void		ft_get_file_major_minor(dev_t st_rdev, unsigned int size_major, unsigned int size_minor);
void		ft_get_file_perms(int st_mode);
void		ft_get_user_perms(int st_mode);
void		ft_get_group_perms(int st_mode);
void		ft_get_other_perms(int st_mode);
void		ft_get_file_links(int st_nlink, unsigned int size_links);
void		ft_get_user(char *pw_name, unsigned int size_user);
void		ft_get_group(char *gr_name, unsigned int size_group);
void		ft_get_size(off_t st_size, unsigned int size_size);
void		ft_get_time_mod(struct timespec st_mtimespec);
int			main(int argc, char **argv);

#endif
