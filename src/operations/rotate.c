/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:43:12 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/08 16:11:20 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

void r_mouv(t_pile *pile)
{
    if (pile->size <= 1)
        return ;
    pile->top = pile->top->next;
}

void ra(t_pile *a, int is_rr)
{
    r_mouv(a);
}

void rb(t_pile *b, int is_rr)
{
    r_mouv(b);
    if (is_rr == 0)
        write(1, "rb\n", 3);
}

void rr(t_pile *a, t_pile *b)
{
    rb(b, 1);
    ra(a, 1);
    write(1, "rr\n", 3);
}
