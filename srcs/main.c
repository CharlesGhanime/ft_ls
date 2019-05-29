/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:32:17 by sikenn            #+#    #+#             */
/*   Updated: 2019/05/29 16:57:38 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <stdio.h>

int     main(int argc, char **argv)
{
    if (argc == 2)
    {
        int ret;
        unsigned int c;

        c = 0x00;
        ft_list_dir(argv[1]);
        ft_inspect_file(argv[1]);
        while ((ret = ft_getopt(argc, argv, "lRxrt")) != -1)         
        {
            printf("ret == %c\nret == %d\n",ret, ret);
        }
    }
    return (0);
}
