/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:43:50 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/20 16:24:31 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rr_mouv(t_pile *pile)
{
    if (pile->size <= 1)
        return ;
    pile->top = pile->top->prev;
}
void rra(t_pile *a)
{
    rr_mouv(a);
    write(1, "rra\n", 4);
}

void rrb(t_pile *b)
{
    rr_mouv(b);
    write(1, "rrb\n", 4);
}

void rrr(t_pile *a, t_pile *b)
{
    rr_mouv(a);
    rr_mouv(b);
    write(1, "rrr\n", 4);
}

