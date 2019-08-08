/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:59:14 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/03 15:48:51 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MEM_H
# define FREE_MEM_H

void	free_list(t_link  *list);
void	free_tab(int **tab, int size);
void	free_tab_char(char **tab, int size);

#endif
