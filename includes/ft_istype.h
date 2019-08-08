/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_istype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:43:41 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/04 17:09:14 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ISTYPE_H
# define FT_ISTYPE_H

int		is_regular_file(char *path);
int		is_dir_file(const char *path);
int		is_link_file(const char *path);

#endif 
