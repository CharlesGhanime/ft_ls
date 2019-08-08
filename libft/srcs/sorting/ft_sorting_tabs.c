/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_tabs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:30:49 by sikenn            #+#    #+#             */
/*   Updated: 2019/07/31 14:44:34 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_sorting_tabs(char **tabs, int index, int length)
{
	char	*tmp;
	int		save_index;

	save_index = index;
	while (index < length - 1)
	{
		if (index < length && (ft_strcmp(tabs[index], tabs[index + 1]) > 0))
		{
			tmp = ft_strdup(tabs[index]);
			tabs[index] = ft_strdup(tabs[index + 1]);
			tabs[index + 1] = ft_strdup(tmp);
			index = save_index;
		}
		else
			index++;
	}
	return (tabs);
}
