/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:34:08 by sikenn            #+#    #+#             */
/*   Updated: 2018/11/26 14:55:28 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_int(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int		count_int_neg(unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_itoa_neg(int n)
{
	char			*s;
	int				i;
	unsigned int	nn;

	nn = n * (-1);
	i = count_int_neg(nn) + 1;
	if (!(s = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	s[i] = '\0';
	i--;
	while (i >= 0)
	{
		s[i] = nn % 10 + '0';
		nn = nn / 10;
		i--;
	}
	s[0] = '-';
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;

	if (n >= 0)
	{
		i = count_int(n);
		if (i == 0)
			i = 1;
		if (!(s = (char *)malloc((i + 1) * sizeof(char))))
			return (NULL);
		s[i] = '\0';
		i--;
		while (i >= 0)
		{
			s[i] = n % 10 + '0';
			n = n / 10;
			i--;
		}
	}
	else
	{
		s = ft_itoa_neg(n);
	}
	return (s);
}
