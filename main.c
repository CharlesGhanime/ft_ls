/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemmou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:30:25 by ichemmou          #+#    #+#             */
/*   Updated: 2019/05/12 14:34:30 by ichemmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "includes/libft.h"

int		main(int ac, char **av)
{
	int i;

	while ((i = getopt(ac, av, "abc")) != -1)
		printf("i == %c\n", i);
}
