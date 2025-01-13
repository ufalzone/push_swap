/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:56:44 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/13 16:49:05 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    sort_3(t_pile *a)
{

}

void    sort_5(t_pile *a, t_pile *b)
{

}

void    sort_big(t_pile *a, t_pile *b)
{
	int best_pos_a;
	int best_pos_b;
	int cost;

	// cost = cost_push_b(a, b, &best_pos_a, &best_pos_b);
	while (a->size > 3)
	{
		cost = cost_push_b(a, b, &best_pos_a, &best_pos_b);
		execute_rotations(a, b, best_pos_a, best_pos_b);
		pb(a, b);
	}
// a suivre
}

void    algo(t_pile *a, t_pile *b)
{
	if (a->size <= 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
		sort_big(a, b);
}


