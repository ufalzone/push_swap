/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:28:59 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/17 19:25:21 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <type_traits>

//Rotation de a, pour amener l'element
//Rotation de B pour placer l'element dans la pileen ordre decroisant, ROTATIVE

//Trouver le int max, et le int min, et trouver l'iindex ou mettre le nombre si c'est un int max ou un int min
void find_max_min(t_pile *pile)
{
	t_number *current;
	int i;

	if (!pile || pile->size == 0)
		return;
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

t_pile *duplicate_pile(t_pile *pile)
{
	t_pile *new_pile;
	t_number *current;
	t_number *new_number;
	int i;

	if (!pile)
		return (NULL);
	new_pile = init_pile();
	if (!new_pile)
		return (NULL);
	current = pile->top;
	i = 0;
	while (i < pile->size)
	{
		new_number = create_number(current->value);
		if (!new_number)
		{
			free_pile(new_pile);
			return (NULL);
		}
		add_front(new_pile, new_number);
		current = current->next;
		i++;
	}
	return (new_pile);
}

int is_sorted_desc(t_pile *pile, t_number *number, int index)
{
	int i;

	i = -1;
	while(++i < pile->size)
	{

	}

}

//Renvoie l'index ou il faut placer l'element de la pile b
int find_target_pos_b(t_number *number, t_pile *b)
{
	t_number *current;
	int i;

	current = b->top;
	find_max_min(b);
	if (number->value > b->max_value)
		return (b->max_index);
	if (number->value < b->min_value)
		return (b->min_index);
	i = -1;
	while (i < b->size)
	{
		if (number->value < current->prev->value && number->value > current->value && is_sorted_desc(b, current, i))
			return (i + 1);
		current = current->next;
		i++;
	}
	return (i);
}

int calculate_cost_desc(int position, t_pile *pile)
{
	if (position > pile->size / 2)
		return (-(pile->size - position));
	return (position);
}

//Calcul le nombre de rotation a faire pour placer l'element de la pile b
void target_pos_desc(t_pile *a, t_pile *b)
{
	t_number *current;
	int i;
	int cost_a;
	int cost_b;
	int cost_total;
	int min_cost;

	current = a->top;
	i = -1;
	min_cost = -1;
	while (++i < a->size)
	{
		cost_a = calculate_cost_desc(i, a);
		cost_b = calculate_cost_desc(find_target_pos_b(current, b), b);
		cost_total = abs(cost_a) + abs(cost_b);
		if (cost_total < min_cost || min_cost == -1)
		{
			min_cost = cost_total;
			a->target_pos = cost_a;
			b->target_pos = cost_b;
		}
		current = current->next;
	}
}
void execute_solomove_desc(t_pile *a, t_pile *b, int target_pos_a, int target_pos_b)
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

void execute_move_desc(t_pile *a, t_pile *b)
{
	int target_pos_a;
	int target_pos_b;

	target_pos_a = a->target_pos;
	target_pos_b = b->target_pos;
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

void sort_2_b(t_pile *b)
{
	if (b->top->value < b->top->next->value)
		rb(b);
}

void test_algo_turk(t_pile *a, t_pile *b)
{
	// display_piles(a, b);
	pb(a, b);
	pb(a, b);
	sort_2_b(b);
	// display_piles(a, b);
	while (a->size > 3)
	{
		target_pos_desc(a, b);
		execute_move_desc(a, b);
		pb(a, b);
	printf("target_pos_a: %d\n", a->target_pos);
	printf("target_pos_b: %d\n", b->target_pos);
		// display_piles(a, b);
	}
	printf("\n");
	printf("target_pos_a: %d\n", a->target_pos);
	printf("target_pos_b: %d\n", b->target_pos);
}
