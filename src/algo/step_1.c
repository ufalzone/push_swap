/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:18:34 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/14 18:51:08 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//parcourir chaque element de a et trouver la position de b qui minimise le cout

#include "../../includes/push_swap.h"

static void find_min_max_in_b_desc(t_pile *b, int *min_index, int *max_index)
{
    t_number *current;
    int      i;

    if (b->size == 0)
        return;

    current = b->top;
    *min_index = current->index;
    *max_index = current->index;

    i = 0;
    while (i < b->size)
    {
        if (current->index < *min_index)
            *min_index = current->index;
        if (current->index > *max_index)
            *max_index = current->index;
        current = current->next;
        i++;
    }
}

static int find_position_in_b_desc(t_number *current, t_pile *b)
{
	t_number *current_b;
	int position;
	int min_index;
	int max_index;

	find_min_max_in_b_desc(b, &min_index, &max_index);

	if (b->size == 0)
		return (0);
	current_b = b->top;
	position = -1;

	if (current->index > max_index)
		return (0);
	if (current->index < min_index)
		return (b->size);
	while (++position < b->size)
	{
		if (current_b->prev->index > current->index
            && current->index > current_b->index)
			return (position);
		current_b = current_b->next;
	}
	return (b->size);
}

static int min(int a, int b)
{
	return (a < b ? a : b);
}



int target_pos(t_pile *a, t_pile *b)
{
	t_number *current;
	int cost_a;
	int cost_b;
	int cost_total;
	int min_cost;
	int position;
	int position_b;

	current = a->top;
	position = -1;
	min_cost = -1;
	while (++position < a->size)
	{
		cost_a = (position > a->size / 2) ? -(a->size - position) : position;
		position_b = find_position_in_b_desc(current, b);
		cost_b = (position_b > b->size / 2) ? -(b->size - position_b) : position_b;
		if (position_b == b->size)
			cost_b = 1;
		cost_total = abs(cost_a) + abs(cost_b);
		if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
            cost_total -= min(abs(cost_a), abs(cost_b));
		if (cost_total < min_cost || min_cost == -1)
		{
			min_cost = cost_total;
			a->target_pos = position;
			b->target_pos = position_b;
		}
		current = current->next;
	}
	return (min_cost);
}
