/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemmou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:19:29 by ichemmou          #+#    #+#             */
/*   Updated: 2019/08/01 14:35:53 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

int			ft_getopt(int ac, char **av, const char *optstring);
extern int	g_optind;
extern int	g_optopt;

#endif
