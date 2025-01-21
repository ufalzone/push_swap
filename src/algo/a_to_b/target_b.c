/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:34:12 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 18:49:46 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

// Renvoie l'index ou il faut placer l'element de la pile b
// dans l'ordre decroissant
int	find_target_pos_b(t_number *number, t_pile *b)
{
	t_number	*current;
	int			i;

	current = b->top;
	find_max_min(b);
	if (number->value > b->max_value)
		return (b->max_index);
	if (number->value < b->min_value)
		return (b->min_index + 1);
	i = -1;
	while (i < b->size)
	{
		if (number->value < current->prev->value
			&& number->value > current->value)
			return (i + 1);
		current = current->next;
		i++;
	}
	return (i + 1);
}

void	target_pos_desc(t_pile *a, t_pile *b)
{
	t_number	*current;
	int			i;
	int			costs[2];
	int			min_cost;

	current = a->top;
	i = -1;
	min_cost = -1;
	while (++i < a->size)
	{
		costs[0] = calculate_cost_desc(i, a);
		costs[1] = calculate_cost_desc(find_target_pos_b(current, b), b);
		if (ft_abs(costs[0]) + ft_abs(costs[1]) < min_cost || min_cost == -1)
		{
			min_cost = ft_abs(costs[0]) + ft_abs(costs[1]);
			a->target_pos = costs[0];
			b->target_pos = costs[1];
		}
		current = current->next;
	}
}
