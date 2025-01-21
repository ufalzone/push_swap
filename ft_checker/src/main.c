/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:05:52 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 20:10:44 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

#include <stdio.h>
void	display_piles(t_pile *a, t_pile *b)
{
	static int	count = 0;
	t_number	*current_a;
	t_number	*current_b;
	int			i;
	int			max_size;

	count++;
	printf("\n=== DISPLAY #%d ===\n", count);
	printf("=== PILE A (%d) === === PILE B (%d) ===\n", a->size, b->size);
	max_size = (a->size > b->size) ? a->size : b->size;
	current_a = a->top;
	current_b = b->top;
	i = 0;
	while (i < max_size)
	{
		if (i < a->size)
		{
			printf("%11d", current_a->value);
			printf("(%d)", current_a->index);
			current_a = current_a->next;
			if (current_a == a->top) // Arrêter quand on revient au début
				current_a = NULL;
		}
		else
			printf("%11s", "");
		printf("     ");
		if (i < b->size)
		{
			printf("%d", current_b->value);
			printf("(%d)", current_b->index);
			current_b = current_b->next;
			if (current_b == b->top) // Arrêter quand on revient au début
				current_b = NULL;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}


int	main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;
	int		*result;
	int		size;

	if (ac < 2)
		return (write(2, "Error\n", 6), 1);
	result = args_to_int(av, ac, &size);
	if (!result)
		return (1);
	if (!already_sorted(result))
		return (write(2, "Error\n", 3), 1);
	init_piles(&a, &b, result, size);
	checking(&a, &b);
	free(result);
	free_piles(&a, &b);
	return (0);
}
