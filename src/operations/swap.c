/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:39:57 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/17 18:01:22 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

//CORRIGER CELA DUPLIQUE

void s_mouv(t_pile *pile)
{
    t_number *first;
    t_number *second;

    if (pile->size <= 1)
        return;
    first = pile->top;
    second = pile->top->next;

    // Mise à jour des connexions externes
    if (pile->size > 2)
        second->next->prev = first;
    first->prev->next = second;

    // Mise à jour des connexions entre first et second
    first->next = second->next;
    second->next = first;
    second->prev = first->prev;
    first->prev = second;

    // Mise à jour du top
    pile->top = second;
}

void sa(t_pile *a)
{
    s_mouv(a);
    write(1, "sa\n", 3);
}

void sb(t_pile *b)
{
    s_mouv(b);
    write(1, "sb\n", 3);
}

void ss(t_pile *a, t_pile *b)
{
    s_mouv(a);
    s_mouv(b);
    write(1, "ss\n", 3);
}

