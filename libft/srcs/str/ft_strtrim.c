/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:36:28 by sikenn            #+#    #+#             */
/*   Updated: 2018/11/26 14:56:14 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lentrim(char const *s)
{
	size_t i;
	size_t space;
	size_t len_trim;

	len_trim = ft_strlen(s);
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	space = i;
	if (s[i] != '\0')
	{
		i = len_trim - 1;
		while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		{
			i--;
			space++;
		}
	}
	return (len_trim - space);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len_trim;

	if (s == NULL)
		return (NULL);
	len_trim = ft_lentrim(s);
	if (!(str = ft_strnew(len_trim)))
		return (NULL);
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	j = 0;
	while (j < len_trim)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
