/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_print_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:58:58 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/10 11:58:59 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

p_func		ft_get_print_l()
{
    return (ft_print_l);
}

p_func		ft_get_print_R()
{
    return (ft_print_R);
}

p_func		ft_get_print_a()
{
    return (ft_print_a);
}

p_func		ft_get_print_r()
{
    return (ft_print_hexa_r);
}

p_func		ft_get_print_t()
{
    return (ft_print_t);
}