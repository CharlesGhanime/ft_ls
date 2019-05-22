/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:52:59 by sikenn            #+#    #+#             */
/*   Updated: 2019/02/28 17:55:34 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H 

# define BUFF_SIZE 4

typedef struct		s_data
{
	int				fd;
	char			*rest;
}					t_data;

int					get_next_line(const int fd, char **line);

#endif
