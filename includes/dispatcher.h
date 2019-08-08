/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:20:01 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/04 18:18:48 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

void	dispatcher(unsigned char flags, char *path, char *target, t_link *node);
void	ft_num_list(t_link *list);

#endif
