/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:43:12 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/20 16:24:53 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

void r_mouv(t_pile *pile)
{
    if (pile->size <= 1)
        return ;
    pile->top = pile->top->next;
}

void ra(t_pile *a)
{
	r_mouv(a);
    write(1, "ra\n", 3);
}

void rb(t_pile *b)
{
    r_mouv(b);
    write(1, "rb\n", 3);
}

void rr(t_pile *a, t_pile *b)
{
    r_mouv(a);
    r_mouv(b);
    write(1, "rr\n", 3);
}

