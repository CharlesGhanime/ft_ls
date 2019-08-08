/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikenn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:32:25 by sikenn            #+#    #+#             */
/*   Updated: 2019/05/29 17:43:02 by sikenn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_print_bits(unsigned char octet)
{
    int i;
    unsigned char c;

    i = 128;
    while (i > 0)
    {
        if (octet < i)
        {
            c = '0';
            ft_putchar(c);
            i /= 2;
        }
        else
        {
            c = '1';
            ft_putchar(c);
            octet = octet - i;
            i /= 2;
        }
    }
}
