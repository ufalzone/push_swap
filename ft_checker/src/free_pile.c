/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:49:06 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 19:49:11 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	free_pile(t_pile *pile)
{
	t_number	*current;
	t_number	*next;
	int			size;

	if (!pile || !pile->top)
		return ;
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

void	free_piles(t_pile *a, t_pile *b)
{
	free_pile(a);
	free_pile(b);
}
