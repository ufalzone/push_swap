/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:56:44 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/16 15:26:00 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_pile *a)
{
}

void	sort_5(t_pile *a, t_pile *b)
{
}

void	sort_2(t_pile *pile, int is_a)
{
	if (is_a == 1)
	{
		if (pile->top->index < pile->top->next->index)
			ra(pile);
	}
	else
	{
		if (pile->top->index < pile->top->next->index)
			rb(pile);
	}
}
// Rotate a recoit a contenant la position de l'element a ramener au top
void	execute_rotate_a(t_pile *a)
{
	int t_pos;

	t_pos = a->target_pos;
	if (t_pos < a->size / 2)
		while (t_pos-- > 0)
			ra(a);
	else
		while (t_pos++ < a->size)
			rra(a);
}

// Rotate b recoit b contenant la position final ou l'element top doit etre ramené
void	execute_rotate_b(t_pile *b)
{
	int t_pos;
	static int temp = 0;
	t_pos = b->target_pos;

	printf("(%d) t_pos: %d | b->size: %d\n", temp++, t_pos, b->size);
	if (t_pos >= b->size - 1) //On calcule les rotations avant de pb qui modifie la taille de size
	{
		rb(b);
		return ;
	}
	if (t_pos == 1)
	{
			sb(b);
			return;
		}
	if (t_pos < b->size / 2)
		while (t_pos-- > 0)
			rb(b);
	else
		while (t_pos++ < b->size)
			rrb(b);
}

void	sort_big(t_pile *a, t_pile *b)
{
	static int	operations = 0;

	pb(a, b);
	pb(a, b);
	sort_2(b, 0);
	// Calculer la target_pos_a et target_pos_b
	// Rotate a de la taget_pos_a jusqu'au top
	// pb
	// Rotate b du top jusqu'à la target_pos_b
	display_piles(a, b);
	while (a->size > 3)
	{
        target_pos(a, b);
		printf("-- %d --\ntarget_pos_a: %d | target_pos_b: %d\nsize_a: %d | size_b: %d\ntop_a: %d | top_b: %d\n\n", operations, a->target_pos, b->target_pos, a->size, b->size, a->top->value, b->top->value);
        // 1. D'abord positionner B pour recevoir le nombre
        // execute_rotate_b(b);
        // 2. Puis positionner A
        execute_rotate_a(a);
        // 3. Enfin faire le push
        pb(a, b);
		execute_rotate_b(b);
		printf("-- %d --\ntarget_pos_a: %d | target_pos_b: %d\nsize_a: %d | size_b: %d\ntop_a: %d | top_b: %d\n\n", operations, a->target_pos, b->target_pos, a->size, b->size, a->top->value, b->top->value);
		operations++;
	}
	sort_3(a);
}

void	algo(t_pile *a, t_pile *b)
{
	if (a->size <= 3)
		sort_3(a);
	else if (a->size <= 5)
		sort_5(a, b);
	else
		sort_big(a, b);
}

int	main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;
	int		*result;

	if (ac <= 2)
		return (write(1, "Error\n", 6), 1);
	result = args_to_int(av, ac);
	if (!result)
		return (1);
	if (!already_sorted(result))
		return (0);
	init_piles(&a, &b, result, ac - 1);
	display_piles(&a, &b);
	algo(&a, &b);
	display_piles(&a, &b);
	free(result);
	return (0);
}
