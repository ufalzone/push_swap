/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:43:50 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/08 16:12:47 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

void rr_mouv(t_pile *pile)
{
    if (pile->size <= 1)
        return ;
    pile->top = pile->top->prev;
}
void rra(t_pile *a, int is_rrr)
{
    rr_mouv(a);
    if (is_rrr == 0)
        write(1, "rra\n", 4);
}

void rrb(t_pile *b, int is_rrr)
{
    rr_mouv(b);
    if (is_rrr == 0)
        write(1, "rrb\n", 4);
}

void rrr(t_pile *a, t_pile *b, int is_rrr)
{
    rra(a, 1);
    rrb(b, 1);
    if (is_rrr == 0)
        write(1, "rrr\n", 4);
}