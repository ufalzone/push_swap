/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:28:59 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 18:33:49 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_big(t_pile *a, t_pile *b)
{
	// display_piles(a, b);
	pb(a, b);
	pb(a, b);
	sort_2_b(b);
	while (a->size > 3)
	{
		target_pos_desc(a, b);
		execute_move_desc(a, b);
		pb(a, b);
	}
	sort_3_a(a);
	// display_piles(a, b);
	while (b->size > 0)
	{
		find_target_pos_a(b->top, a);
		// printf("target_pos: %d\n", a->target_pos);
		// display_piles(a, b);
		execute_move_asc(a);
		pa(a, b);
	}
	// display_piles(a, b);
	final_sort(a);
	// display_piles(a, b);
}

//Choix de l'algo de tri
void	algo_sorting(t_pile *a, t_pile *b)
{
	if (a->size == 2)
		sort_2_a(a);
	else if (a->size == 3)
		sort_3_a(a);
	else
		sort_big(a, b);
}
