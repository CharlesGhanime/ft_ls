/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:39:56 by cghanime          #+#    #+#             */
/*   Updated: 2019/06/10 11:40:01 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

boolean			is_token(char token, char c)
{
    if (c == token)
        return (TRUE);
    return (FALSE);
}

boolean			is_param(size_t bool_param)
{
    if (bool_param != TRUE)
        return (TRUE);
    return (FALSE);
}

void ft_lst_param_token(t_param lst_param[NB_PARAM])
{
    lst_param[L_MIN].token = ft_get_l();
    lst_param[R_MAJ].token = ft_get_R();
    lst_param[A_MIN].token = ft_get_a();
    lst_param[R_MIN].token = ft_get_r();
    lst_param[T_MIN].token = ft_get_t();

    lst_param[L_MIN].next_param = R_MAJ;
    lst_param[R_MAJ].next_param = A_MIN;
    lst_param[A_MIN].next_param = R_MIN;
    lst_param[R_MIN].next_param = T_MIN;
    lst_param[T_MIN].next_param = NO_PARAM;

    lst_param[L_MIN].func = ft_get_print_l();
    lst_param[R_MAJ].func = ft_get_print_R();
    lst_param[A_MIN].func = ft_get_print_a();
    lst_param[R_MIN].func = ft_get_print_r();
    lst_param[T_MIN].func = ft_get_print_t();
}

void			ft_param_cmp(char c, t_stock *stock)
{
    size_t			check_param = FALSE;
    t_param		lst_param[NB_PARAM];
    PARAM_TOKEN	current_param = CHAR;

    ft_lst_param_token_init(lst_param);
    while (current_param != NO_PARAM)
    {
        if (lst_param[current_param].token == c)
        {
            lst_param[current_param].func(stock);
            check_param = TRUE;
        }
        current_param = lst_param[current_param].next_param;
    }
    if (is_param(check_param) == TRUE)
    {
        ft_putchar('-');
        ft_putchar(c);
    }
}

int				ft_ls(const char *param, ...)
{
    t_stock *stock = NULL;
    int i;

//    stock = init_head(stock);
//    ft_count_pct((char *)param, &percents);
//    blood_test(&percents);
    i = 0;

    while (param[i])
    {
        if (is_token('-', param[i]) == TRUE)
        {
            ft_param_cmp(arg, param[++i], percents);
        }
        if (if_token('-', param[i] != TRUE))
        {
            //la on print ce que le ls sans argument print
        }
        i++;
    }
//    global_info(percents);
    return (ft_strlen((char *)param));
}
