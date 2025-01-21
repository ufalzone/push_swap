/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:33:20 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 18:14:16 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

//Tri les 2 elements push de b
void	sort_2_b(t_pile *b)
{
	if (b->top->value < b->top->next->value)
		rb(b);
}

//Rotation de a et b solo (ra, rb, rra, rrb)
void	execute_solomove_desc(t_pile *a, t_pile *b, int target_pos_a,
		int target_pos_b)
{
	while (target_pos_a > 0)
	{
		ra(a);
		target_pos_a--;
	}
	while (target_pos_b > 0)
	{
		rb(b);
		target_pos_b--;
	}
	while (target_pos_a < 0)
	{
		rra(a);
		target_pos_a++;
	}
	while (target_pos_b < 0)
	{
		rrb(b);
		target_pos_b++;
	}
}

//Optimisation de la rotation a et b (rr, rrr)
void	execute_move_desc(t_pile *a, t_pile *b)
{
	int	target_pos_a;
	int	target_pos_b;

	target_pos_a = a->target_pos;
	target_pos_b = b->target_pos;
	// Convertir en rotations négatives si plus optimal
	if (target_pos_a > a->size / 2)
		target_pos_a = -(a->size - target_pos_a);
	if (target_pos_b > b->size / 2)
		target_pos_b = -(b->size - target_pos_b);
	// Rotations simultanées
	while (target_pos_a > 0 && target_pos_b > 0)
	{
		rr(a, b);
		target_pos_a--;
		target_pos_b--;
	}
	while (target_pos_a < 0 && target_pos_b < 0)
	{
		rrr(a, b);
		target_pos_a++;
		target_pos_b++;
	}
	execute_solomove_desc(a, b, target_pos_a, target_pos_b);
}
