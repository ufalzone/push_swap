/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:14:38 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/13 12:25:01 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    push_back(t_pile *pile, t_number *new)
{
    if (pile->top == NULL)
    {
        pile->top = new;
        new->next = new;
        new->prev = new;
        pile->size = 1;
        return;
    }
    new->next = pile->top;
    new->prev = pile->top->prev;
    pile->top->prev->next = new;
    pile->top->prev = new;
    pile->size++;
}

t_number *init_number(int value)
{
	t_number *number;

	number = (t_number *)malloc(sizeof(t_number));
	if (!number)
		return (NULL);
	number->value = value;
	number->index = -1;
	number->next = NULL;
	number->prev = NULL;
	return (number);
}

void init_piles(t_pile *a, t_pile *b, int *result, int ac)
{
	int i;
	t_number *tmp;

	a->top = NULL;
	b->top = NULL;
	b->size = 0;
	i = 0;
	while (i < ac)
	{
		tmp = init_number(result[i]);
		push_back(a, tmp);
		i++;
	}
	rank_init(a);
}
