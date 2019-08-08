/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 16:18:00 by sikenn            #+#    #+#             */
/*   Updated: 2019/07/30 18:01:29 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    usage(const char *usage, char illegal)
{
    ft_putstr("ls: illegal option -- ");
    ft_putchar(illegal);
    ft_putstr("\nusage: ls [-");
    ft_putstr(usage);
    ft_putendl("] [file...]");
}

void	error_open_dir(char *dir)
{
	ft_putstr("ft_ls: ");
	ft_putstr(dir);
	ft_putendl(": No such file or directory");
}
