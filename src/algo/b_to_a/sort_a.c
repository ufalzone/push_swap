/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:44:05 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 18:40:11 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sort_2_a(t_pile *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

// 3 2 1
// 3 1 2
// 2 1 3
// 1 3 2
// 2 3 1
void	sort_3_a(t_pile *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
	if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && top > bot && mid < bot)
		ra(a);
	else if (top > mid && top < bot)
		sa(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

// Renvoie l'index ou il faut placer l'element de la pile a dans l'ordre croissant
int	find_target_pos_a(t_number *number, t_pile *a)
{
	t_number	*current;
	int			i;

	current = a->top;
	find_max_min(a);
	if (number->value > a->max_value)
		return (a->target_pos = a->max_index + 1);
	if (number->value < a->min_value)
		return (a->target_pos = a->min_index);
	i = -1;
	while (++i < a->size)
	{
		if (number->value > current->prev->value
			&& number->value < current->value)
			return (a->target_pos = i);
		current = current->next;
	}
	return (a->target_pos = i);
}
