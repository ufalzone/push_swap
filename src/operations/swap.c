/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:39:57 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/20 16:47:17 by ufalzone         ###   ########.fr       */
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

    // Mise à jour des liens entre first, second, et leurs voisins
    first->prev->next = second; // L'élément avant first pointe maintenant vers second
    second->next->prev = first; // L'élément après second pointe maintenant vers first

    first->next = second->next; // First pointe vers le suivant de second
    second->next = first;       // Second pointe vers first
    second->prev = first->prev; // Second pointe vers l'ancien précédent de first
    first->prev = second;       // First pointe vers second

    // Mise à jour du sommet de la pile
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

