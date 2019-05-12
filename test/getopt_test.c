/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichemmou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:30:25 by ichemmou          #+#    #+#             */
/*   Updated: 2019/05/12 16:01:11 by ichemmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../includes/libft.h"

int		main(int ac, char **av)
{
	int ret;

	ret = 0;
	printf(" --- fonction originale ---\n\n");
	while ((ret = getopt(ac, av, "abc")) != -1)
		printf("ret == %c\nret == %d\n",ret,  ret); 
	printf("\n");
	ret = 0;
	printf(" --- fonction chinoise ---\n\n");
	while ((ret = ft_getopt(ac, av, "abc")) != -1)
		printf("ret == %c\nret == %d\n",ret,  ret); 
}
