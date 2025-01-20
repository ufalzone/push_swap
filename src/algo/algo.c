/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:28:59 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/20 17:05:00 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotation de a, pour amener l'element
// Rotation de B pour placer l'element dans la pileen ordre decroisant, ROTATIVE

// Trouver le int max, et le int min, et trouver l'iindex ou mettre le nombre si c'est un int max ou un int min
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

// trouver le int max. parcour a paritr de lui, rajouter le number a l'index et voir si ca change l'ordre decroissant de la pile

//soucis l'index n'est pas bon car on donne l'index d'ou on veut mettre number dans la pile b, mais pas l'index a partir du max
// int	is_sorted_desc(t_pile *pile, t_number *number, int target_index)
// {
// 	int			i;
// 	t_number	*current;
// 	t_number	*start;
// 	int			first_pass;
// 	int			relative_index;

// 	current = pile->top;
// 	i = -1;
// 	// On se déplace jusqu'à max_index
// 	while (++i < pile->max_index)
// 		current = current->next;

// 	// On calcule l'index relatif par rapport à max_index
// 	if (target_index >= pile->max_index)
// 		relative_index = target_index - pile->max_index;
// 	else
// 		relative_index = pile->size - pile->max_index + target_index;

// 	start = current;
// 	i = 0;
// 	first_pass = 1;
// 	while (first_pass || current->next != start)
// 	{
// 		if (current == start)
// 			first_pass = 0;
// 		if (i == relative_index)
// 		{
// 			if (!(current->value > number->value
// 					&& number->value > current->next->value))
// 				return (0);
// 		}
// 		else
// 		{
// 			if (current->value < current->next->value)
// 				return (0);
// 		}
// 		current = current->next;
// 		i++;
// 	}
// 	printf("c'est triee !!\n");
// 	return (1);
// }

// Renvoie l'index ou il faut placer l'element de la pile b
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
	// printf("bonsoir non: %d\n", i);
	return (i + 1);
}

int	calculate_cost_desc(int position, t_pile *pile)
{
	if (position > pile->size / 2)
		return (-(pile->size - position));
	return (position);
}

// Calcul le nombre de rotation a faire pour placer l'element de la pile b
void	target_pos_desc(t_pile *a, t_pile *b)
{
	t_number	*current;
	int			i;
	int			cost_a;
	int			cost_b;
	int			cost_total;
	int			min_cost;

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

void	execute_move_desc(t_pile *a, t_pile *b)
{
	int	target_pos_a;
	int	target_pos_b;

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

void	sort_2_b(t_pile *b)
{
	if (b->top->value < b->top->next->value)
		rb(b);
}

void sort_3_a(t_pile *a)
{
    int top;
    int mid;
    int bot;

	top = a->top->value;
	mid = a->top->next->value;
	bot = a->top->next->next->value;
    if (top > mid && mid > bot) // 3 2 1
    {
        sa(a);
        rra(a);
    }
    else if (top > mid && top > bot && mid < bot) // 3 1 2
        ra(a);
    else if (top > mid && top < bot) // 2 1 3
        sa(a);
    else if (top < mid && mid > bot && top < bot) // 1 3 2
    {
        sa(a);
        ra(a);
    }
    else if (top < mid && mid > bot && top > bot) // 2 3 1
        rra(a);
}

void	test_algo_turk(t_pile *a, t_pile *b)
{

	// display_piles(a, b);
	// pb(a, b);
	// pb(a, b);
	// sort_2_b(b);
	// display_piles(a, b);
	while (a->size > 3)
	{
		target_pos_desc(a, b);
		execute_move_desc(a, b);
		pb(a, b);
	// 	// printf("target_pos_a: %d\n", a->target_pos);
	// 	// printf("target_pos_b: %d\n", b->target_pos);
	// 	// display_piles(a, b);
	}
	sort_3_a(a);
	// display_piles(a, b);
	// display_piles(a, b);
	// while (size != 0)
	// {
	// 	printf("a: %d\n", current->value);
	// 	current = current->next;
	// 	size--;
	// }
	// printf("\n");
	// printf("target_pos_a: %d\n", a->target_pos);
	// printf("target_pos_b: %d\n", b->target_pos);
}
