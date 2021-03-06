/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:10:39 by sikenn            #+#    #+#             */
/*   Updated: 2018/11/26 16:22:29 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int res;
	int neg;

	res = 0;
	neg = 1;
	while (*str == ' ' || *str == '\f' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v')
		str++;
	if (*str == '-')
		neg *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*(str++) - '0');
	return (res * neg);
}
