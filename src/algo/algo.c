/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:28:59 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/17 15:06:37 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//Rotation de a, pour amener l'element
//Rotation de B pour placer l'element dans la pileen ordre decroisant, ROTATIVE

void find_max_min(t_pile *pile)
{
	t_number *current;
	int i;

	if (!pile || pile->size == 0)
		return;
	current = pile->top;
	pile->max_value = current->value;
	pile->min_value = current->value;
	i = -1;
	while (++i < pile->size)
	{
		if (current->value > pile->max_value)
			pile->max_value = current->value;
		if (current->value < pile->min_value)
			pile->min_value = current->value;
		current = current->next;
		i++;
	}
}

//Renvoie l'index ou il faut placer l'element de la pile b

int find_target_pos_b(t_number *number, t_pile *b)
{


}

//Calcul le nombre de rotation a faire pour placer l'element de la pile b
void calculate_rotation_desc(t_pile *a, t_pile *b)
{
	int i;
	int cost;

	i = -1;
	while (++i < a->size)
	{
		cost = find_target_pos_b(a->top, b);
	}

}

void test_algo_turk(t_pile *a, t_pile *b)
{
	pb(a, b);
	pb(a, b);
	calculate_rotation_desc(a, b);


}
