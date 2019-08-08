/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:39:39 by sikenn            #+#    #+#             */
/*   Updated: 2019/08/01 13:46:09 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char    parsing(int argc, char **argv)
{
    int ret;
    unsigned char octet;

    octet = 0;
    while ((ret = ft_getopt(argc, argv, PARAMS)) != -1)
    {
		if (ret == '?')
		{
			usage(PARAMS, g_optopt);
			exit(0);
		}
		else if (ret == PARAMS[0])
            octet |= 1 << 0;
		else if (ret == PARAMS[1])
            octet |= 1 << 1;
		else if (ret == PARAMS[2])
            octet |= 1 << 2;
		else if (ret == PARAMS[3])
            octet |= 1 << 3;
		else if (ret == PARAMS[4])
            octet |= 1 << 4;
		else if (ret == PARAMS[5])
            octet |= 1 << 5;
		else if (ret == PARAMS[6])
            octet |= 1 << 6;
		else if (ret == PARAMS[7])
            octet |= 1 << 7;
    } 
    return (octet);
}
