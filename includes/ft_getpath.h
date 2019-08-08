/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:46:57 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/04 17:01:54 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETPATH_H
# define FT_GETPATH_H

char	*init_path(char *name);
char	*ft_addir(char *path, char *dir);
char	*ft_adddir(char *path, char *dir);
char	*ft_deldir(char *path);
char	*ft_testddir(char *path, char *dir);

#endif
