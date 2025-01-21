/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:39:57 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 18:51:50 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"

void	s_mouv(t_pile *pile)
{
	t_number	*first;
	t_number	*second;

	if (pile->size <= 1)
		return ;
	first = pile->top;
	second = pile->top->next;
	first->prev->next = second;
	second->next->prev = first;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	pile->top = second;
}

void	sa(t_pile *a)
{
	s_mouv(a);
	write(1, "sa\n", 3);
}

void	sb(t_pile *b)
{
	s_mouv(b);
	write(1, "sb\n", 3);
}

void	ss(t_pile *a, t_pile *b)
{
	s_mouv(a);
	s_mouv(b);
	write(1, "ss\n", 3);
}
