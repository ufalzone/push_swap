/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:36:46 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/13 17:24:42 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	do_rotation(t_pile *pile, int *pos, int is_a)
{
	while (*pos != 0)
	{
		if (*pos < 0)
		{
			if (is_a)
				rra(pile, 0);
			else
				rrb(pile, 0);
			(*pos)++;
		}
		else
		{
			if (is_a)
				ra(pile, 0);
			else
				rb(pile, 0);
			(*pos)--;
		}
	}
}

void	execute_rotations(t_pile *a, t_pile *b, int best_pos_a, int best_pos_b)
{
	while (best_pos_a > 0 && best_pos_b > 0)
	{
		rr(a, b);
		best_pos_a--;
		best_pos_b--;
	}
	while (best_pos_a < 0 && best_pos_b < 0)
	{
		rrr(a, b);
		best_pos_a++;
		best_pos_b++;
	}
	// printf("best_pos_a: %d, best_pos_b: %d\n", best_pos_a, best_pos_b);
	do_rotation(a, &best_pos_a, 1);
	do_rotation(b, &best_pos_b, 0);
}

static int	get_position_cost(int position, int size)
{
	if (position <= size / 2)
		return (position);
	return (size - position);
}

static void find_min_max_in_b(t_pile *b, int *min_index, int *max_index)
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

static int find_position_in_b(t_number *elem, t_pile *b)
{
    t_number *current;
    int      i;
    int      max_index;
    int      min_index;

    if (b->size == 0)
        return (0);

    // 1) Trouver min et max dans B
    find_min_max_in_b(b, &min_index, &max_index);

    // 2) Si elem > tout le monde => on le met en top (position = 0)
    if (elem->index > max_index)
        return (0);

    // 3) Si elem < tout le monde => on le met en bas (position = b->size)
    if (elem->index < min_index)
        return (b->size);

    // 4) Sinon on trouve le "trou"
    current = b->top;
    i = 0;
    while (i < b->size)
    {
        if (current->prev->index >= elem->index
            && elem->index >= current->index)
            return (i);
        current = current->next;
        i++;
    }
    // Par sécurité, si rien trouvé (rare), on le met en bas
    return (b->size);
}

int	cost_push_b(t_pile *a, t_pile *b, int *best_pos_a, int *best_pos_b)
{
	t_number	*current;
	int			pos_a;
	int			min_cost;
	int			current_cost;
	int			pos_b;

	current = a->top;
	pos_a = 0;
	min_cost = -1;
	while (pos_a < a->size)
	{
		pos_b = find_position_in_b(current, b);
		if (pos_a > a->size / 2)
			current_cost = a->size - pos_a;
		else
			current_cost = pos_a;
		if (pos_b > b->size / 2)
			current_cost += b->size - pos_b;
		else
			current_cost += pos_b;
		if (min_cost == -1 || current_cost < min_cost)
		{
			min_cost = current_cost;
			*best_pos_a = pos_a;
			*best_pos_b = pos_b;
		}
		current = current->next;
		pos_a++;
	}
	if (*best_pos_a > a->size / 2)
		*best_pos_a = -(a->size - *best_pos_a);
	if (*best_pos_b > b->size / 2)
		*best_pos_b = -(b->size - *best_pos_b);
	return (min_cost);
}
