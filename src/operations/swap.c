/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:39:57 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/08 16:13:32 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

void s_mouv(t_pile *pile)
{
    t_number *first;
    t_number *second;

    if (pile->size <= 1)
        return;
    first = pile->top;
    second = pile->top->next;
    first->next = second->next;
    first->prev = second;
    second->next = first;
    second->prev = first->prev;
    first->next->prev = first;
    second->prev->next = second;
    pile->top = second;
}

void sa(t_pile *a, int is_ss)
{
    s_mouv(a);
    if (is_ss == 0)
        write(1, "sa\n", 3);
}

void sb(t_pile *b, int is_ss)
{
    s_mouv(b);
    if (is_ss == 0)
        write(1, "sb\n", 3);   
}

void ss(t_pile *a, t_pile *b)
{
    sa(a, 1);
    sb(b, 1);
    write(1, "ss\n", 3);
}
