/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:59:57 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/06 19:56:37 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		ft_aug_tab(t_out *out)
{
	int		i;
	int		j;

	i = 0;
	while (i < out->r)
	{
		j = 0;
		while (j < out->c)
		{
			if (out->tab[i][j] != -1)
				out->tab[i][j]++;
			j++;
		}
		i++;
	}
}

static void		ft_fill_tab(t_out *out)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (j <= (out->c - 1))
	{
		i = 0;
		while (out->tab[i] != NULL)
		{
			if (k < out->elem)
				out->tab[i][j] = k;
			else
				out->tab[i][j] = -1;
			i++;
			k++;
		}
		j++;
	}
}

static void		ft_mk_tab2(t_out *out)
{
	int		i;

	out->tab = NULL;
	if (!(out->tab = (int **)malloc(sizeof(int *)
			* ((unsigned long)out->r + 1))))
		return ;
	out->tab[out->r] = NULL;
	i = 0;
	while (i < out->r)
	{
		if (!(out->tab[i] = (int *)malloc(sizeof(int)
				* ((unsigned long)out->c))))
			return ;
		out->tab[i][out->c] = -1;
		i++;
	}
	int j;
	i = 0;
	while (out->tab[i] != NULL)
	{
		j = 0;
		while (out->tab[i][j] != -1)
			j++;
		i++;
	}
	ft_fill_tab(out);
}

static void		ft_make_len(t_out *out, t_link *dir)
{
	out->len = 0;
	while (dir != NULL)
	{
		if (ft_strncmp(dir->name, ".", 1) != 0)
		{
			if (dir->namelen > out->len)
				out->len = dir->namelen;
		}
		dir = dir->next;
	}
}

static void		ft_cnt_elem(t_out *out, t_link *dir)
{
	int		i;

	i = 0;
	while (dir != NULL)
	{
		if (ft_strncmp(dir->name, ".", 1) != 0)
			i++;
		dir = dir->next;
	}
	out->elem = i;
}

static void		ft_fill_space(t_out *out)
{
	int		i;

	i = 0;
	out->space[out->len + 1] = '\0';
	while (i < out->len)
	{
		out->space[i] = ' ';
		i++;
	}
}

static void		ft_print_tablink(t_out *out)
{
	int		i;
	int		j;
	int		k;
	t_link	*dir;

	i = 0;
	k = 0;
	while (out->tab[i] != NULL)
	{
		j = 0;
		while (out->tab[i][j] != -1 && j < out->c)
		{
			dir = out->tmp;
			while (dir->next && dir->nbr != out->tab[i][j])
				dir = dir->next;
			if (*dir->name - '.' == 0)
			{
				ft_aug_tab(out);
				dir = out->tmp;
			}
			else
			{
				ft_putstr(dir->name);
				write(1, out->space, (out->len - dir->namelen + 1));
				j++;
				k++;
			}
		}
		if (out->tab[i + 1] || out->c > 1)
			write(1, "\n", 1);
		i++;
	}
	free(out->space);
	free_tab(out->tab, out->r);
}

static void		ft_mk_tab(t_out *out)
{
	out->c = out->elem;
	out->r = 1;
	if (((out->c * (out->len + 1))) > out->w.ws_col)
		out->c = ((out->c / 2) + (out->c % 2));
	while (((out->c * (out->len + 1))) > out->w.ws_col && (out->c - 1) > 0)
		out->c--;
	if (out->c > 1)
		out->c -= 1;
	while ((out->r * out->c) <= out->elem)
		out->r++;
	ft_mk_tab2(out);
	ft_print_tablink(out);
}

void			basic_output(t_link *dir)
{
	t_out	out;

	out.elem = 0;
	out.len = 0;
	out.tmp = dir;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &out.w);
	ft_make_len(&out, dir);
	ft_cnt_elem(&out, dir);
	if (!(out.space = (char *)malloc(sizeof(char) * (out.len + 2))))
		return ;
	ft_fill_space(&out);
	ft_mk_tab(&out);
}

void			output_path(char *path)
{
	ft_putstr(path);
	ft_putchar(':');
	ft_putchar('\n');
}
