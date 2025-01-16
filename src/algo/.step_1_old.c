/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_1_old.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:36:46 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/14 16:33:38 by ufalzone         ###   ########.fr       */
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
				rra(pile);
			else
				rrb(pile);
			(*pos)++;
		}
		else
		{
			if (is_a)
				ra(pile);
			else
				rb(pile);
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
	do_rotation(a, &best_pos_a, 1);
	do_rotation(b, &best_pos_b, 0);
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

    find_min_max_in_b(b, &min_index, &max_index);

    if (elem->index > max_index)
        return (0);

    if (elem->index < min_index)
        return (b->size);

    current = b->top;
    i = 0;
    while (i < b->size)
    {
        if (current->prev->index > elem->index
            && elem->index > current->index)
            return (i);
        current = current->next;
        i++;
    }
    return (b->size);
}

static int get_rotation_cost_b(int pos_b, int size_b)
{
    // Cas particulier : on veut se placer "tout en bas" => nécessite 1 rrb
    if (pos_b == size_b && size_b > 0)
        return (1);

    // Sinon, formule habituelle
    if (pos_b <= size_b / 2)
        return (pos_b);
    else
        return (size_b - pos_b);
}

static int min(int a, int b)
{
    return (a < b) ? a : b;
}
// int cost_push_b(t_pile *a, t_pile *b, int *best_pos_a, int *best_pos_b)
// {
//     t_number    *current;
//     int         pos_a;
//     int         min_cost;
//     int         current_cost;
//     int         pos_b;
//     int         cost_a;
//     int         cost_b;

//     current = a->top;
//     pos_a = 0;
//     min_cost = -1;
//     *best_pos_a = -1;
//     *best_pos_b = -1;

//     while (pos_a < a->size)
//     {
//         pos_b = find_position_in_b(current, b);
//         // Convertir les positions en coûts (positif ou négatif)
//         cost_a = (pos_a > a->size / 2) ? -(a->size - pos_a) : pos_a;
//         cost_b = get_rotation_cost_b(pos_b, b->size);

//         // Calculer le coût réel en tenant compte des mouvements combinés
//         current_cost = abs(cost_a) + abs(cost_b);
//         if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
//             current_cost -= min(abs(cost_a), abs(cost_b));

//         if (min_cost == -1 || current_cost < min_cost)
//         {
//             min_cost = current_cost;
//             *best_pos_a = pos_a;
//             *best_pos_b = pos_b;
//         }
//         current = current->next;
//         pos_a++;
//     }

//     // Conversion des positions en mouvements
//     if (*best_pos_a > a->size / 2)
//         *best_pos_a = -(a->size - *best_pos_a);
//     if (*best_pos_b > b->size / 2)
//         *best_pos_b = -(b->size - *best_pos_b);

//     return (min_cost);
// }
