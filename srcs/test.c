/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:31:37 by sikenn            #+#    #+#             */
/*   Updated: 2019/07/01 06:21:46 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <stdio.h>

int			main(void)
{
	ft_putendl(ft_deldir("./troll/bin"));
	
	if (ft_strcmp("./troll", ft_deldir("./troll/bin")) == 0)
		printf("Test 1: Passed\n");
	else
		printf("Test 1: Failed\n");

	if (ft_strcmp(".", ft_deldir("./")) == 0)
		printf("Test 2: Passed\n");
	else
		printf("Test 2: Failed\n");

	ft_putendl(ft_addir("./troll", "test"));
	if (ft_strcmp("./troll/test", ft_addir("./troll", "test")) == 0) 
		printf("ft_addir test1 passed");
	else
		printf("ft_addir test1: Failed");
	return (0);

}
