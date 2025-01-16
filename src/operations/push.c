/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:42:32 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/14 17:16:16 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/struct.h"

static void push_empty(t_pile *dest, t_number *node)
{
    dest->top = node;
    node->next = node;
    node->prev = node;
    dest->size++;
}

static void push_nonempty(t_pile *dest, t_number *node)
{
    node->next = dest->top;
    node->prev = dest->top->prev;
    dest->top->prev->next = node;
    dest->top->prev = node;
    dest->top = node;
    dest->size++;
}

static t_number *pop_node(t_pile *src)
{
    t_number *node;

    if (src->size == 0)
        return (NULL);
    node = src->top;
    if (src->size == 1)
    {
        src->top = NULL;
    }
    else
    {
        src->top = node->next;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    node->next = NULL;
    node->prev = NULL;
    src->size--;
    return (node);
}

void pa(t_pile *a, t_pile *b)
{
    t_number *node;

    node = pop_node(b);
    if (!node)
        return;
    if (a->size == 0)
        push_empty(a, node);
    else
        push_nonempty(a, node);
    write(1, "pa\n", 3);
}

void pb(t_pile *a, t_pile *b)
{
    t_number *node;

    node = pop_node(a);
    if (!node)
        return;
    if (b->size == 0)
        push_empty(b, node);
    else
        push_nonempty(b, node);
    write(1, "pb\n", 3);
}

