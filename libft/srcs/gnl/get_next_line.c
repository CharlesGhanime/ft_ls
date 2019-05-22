/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:33:39 by sikenn            #+#    #+#             */
/*   Updated: 2019/02/27 17:23:25 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int		add_rest(t_list **lines, int fd, char *rest)
{
	t_list *tmp;
	t_list *newlist;
	t_data *data;

	tmp = *lines;
	ft_strchr(rest, '\n') ? (rest = ft_strdup(ft_strchr(rest, '\n') + 1))
		: (rest = NULL);
	while (tmp)
	{
		if (((t_data*)tmp->content)->fd == fd)
		{
			((t_data*)tmp->content)->rest = rest;
			return (1);
		}
		tmp = tmp->next;
	}
	if (!(data = malloc(sizeof(t_data))))
		return (-1);
	data->rest = rest;
	data->fd = fd;
	newlist = ft_lstnew(data, sizeof(t_data));
	free(data);
	ft_lstadd(lines, newlist);
	return (1);
}

char	*find_rest(t_list *lines, int fd)
{
	t_list *tmp;

	tmp = lines;
	while (tmp)
	{
		if (((t_data*)tmp->content)->fd == fd)
			return (((t_data*)tmp->content)->rest);
		tmp = tmp->next;
	}
	return (NULL);
}

void	free_lst(t_list **lines, int fd)
{
	t_list *temp;
	t_list *prev;

	temp = *lines;
	if (temp && ((t_data*)temp->content)->fd == fd)
	{
		*lines = temp->next;
		free((t_data*)temp->content);
		free(temp);
		return ;
	}
	while (temp && ((t_data*)temp->content)->fd != fd)
	{
		prev = temp;
		temp = temp->next;
	}
	if (!temp)
		return ;
	prev->next = temp->next;
	free(((t_data*)temp->content)->rest);
	free((t_data*)temp->content);
	free(temp);
}

int		assembler(char **line, t_list **lines, int fd)
{
	if (!*line || ft_strlen(*line) == 0)
		return (0);
	if (add_rest(lines, fd, *line))
	{
		if (ft_strindex(*line, '\n') >= 0)
		{
			*line = ft_strsubf(*line, 0, ft_strindex(*line, '\n'));
			return (1);
		}
	}
	if (ft_strcmp(*line, ""))
	{
		free_lst(lines, fd);
		return (1);
	}
	*line = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*lines = NULL;
	int				ret;
	char			*buff;

	ret = 0;
	if ((!line) || fd < 0 ||
			(!(buff = (char *)malloc((BUFF_SIZE + 1) * sizeof(char)))))
		return (-1);
	*line = find_rest(lines, fd);
	if (!*line)
		*line = ft_strdup("");
	while (ft_strindex(*line, '\n') < 0 &&
		(ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		*line = ft_strjoinf(line, &buff, 1);
	}
	free(buff);
	if (ret < 0)
		return (-1);
	ret = assembler(line, &lines, fd);
	return (ret);
}
