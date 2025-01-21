/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:38:01 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 17:05:43 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Trouver le int max, et le int min et son index
void	find_max_min(t_pile *pile)
{
	t_number	*current;
	int			i;

	if (!pile || pile->size == 0)
		return ;
	current = pile->top;
	pile->max_value = current->value;
	pile->min_value = current->value;
	pile->max_index = 0;
	pile->min_index = 0;
	i = -1;
	while (++i < pile->size)
	{
		if (current->value > pile->max_value)
		{
			pile->max_value = current->value;
			pile->max_index = i;
		}
		if (current->value < pile->min_value)
		{
			pile->min_value = current->value;
			pile->min_index = i;
		}
		current = current->next;
	}
}
static void free_pile(t_pile *pile)
{
	t_number *current;
	t_number *next;
	int size;

	if (!pile || !pile->top)
		return;
	current = pile->top;
	size = pile->size;

	while (size > 0)
	{
		next = current->next;
		free(current);
		current = next;
		size--;
	}
}

void free_piles(t_pile *a, t_pile *b)
{
	free_pile(a);
	free_pile(b);
}
