/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:42:32 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/06 16:47:06 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

void pa(t_pile *a, t_pile *b)
{
    t_number *temp;
    
    if (b->size == 0)
        return;
    temp = b->top;
    b->top = b->top->next;
    b->size--;
    if (b->size == 0)
        b->top = NULL;
    if (a->size == 0)
    {
        a->top = temp;
        temp->next = temp;
        temp->prev = temp;
    }
    else
    {
        temp->next = a->top;
        temp->prev = a->top->prev;
        a->top->prev->next = temp;
        a->top->prev = temp;
        a->top = temp;
    }
    a->size++;
    write(1, "pa\n", 3);
}

void pb(t_pile *a, t_pile *b)
{
    t_number *temp;
    
    if (a->size == 0)
        return;
    temp = a->top;
    a->top = a->top->next;
    a->size--;
    if (a->size == 0)
        a->top = NULL;
    if (b->size == 0)
    {
        b->top = temp;
        temp->next = temp;
        temp->prev = temp;
    }
    else
    {
        temp->next = b->top;
        temp->prev = b->top->prev;
        b->top->prev->next = temp;
        b->top->prev = temp;
        b->top = temp;
    }
    b->size++;
    write(1, "pb\n", 3);
}
