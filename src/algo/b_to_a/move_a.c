/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:42:39 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 18:41:02 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	execute_move_asc(t_pile *a)
{
	int	target_pos;

	target_pos = a->target_pos;
	if (target_pos > a->size / 2)
	{
		target_pos = -(a->size - target_pos);
	}
	while (target_pos > 0)
	{
		ra(a);
		target_pos--;
	}
	while (target_pos < 0)
	{
		rra(a);
		target_pos++;
	}
}

void	final_sort(t_pile *a)
{
	find_max_min(a);
	while (a->top->value != a->min_value)
	{
		if (a->min_index > a->size / 2)
			rra(a);
		else
			ra(a);
	}
}
