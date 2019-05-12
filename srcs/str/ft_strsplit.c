/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:38:01 by sikenn            #+#    #+#             */
/*   Updated: 2018/11/26 11:42:07 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_wordcounter(char const *s, char c)
{
	size_t i;
	size_t wordcounter;

	i = 0;
	wordcounter = 0;
	while (s[i])
	{
		if (s[i] != c)
			wordcounter++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (wordcounter);
}

static char		**ft_filling(char const *s, char c, char **tab)
{
	size_t begin;
	size_t end;
	size_t i;

	begin = 0;
	end = 0;
	i = 0;
	while (s[end])
	{
		begin = end;
		while (s[begin] && s[begin] == c)
			begin++;
		end = begin;
		while (s[end] && s[end] != c)
			end++;
		if (end - begin != 0)
			tab[i++] = ft_strndup((char *)s + begin, end - begin);
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char **str;

	if (s == NULL)
		return (NULL);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_wordcounter(s, c) + 1))))
		return (NULL);
	return (ft_filling(s, c, str));
}
