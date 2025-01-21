/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:48:14 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 18:42:11 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_pile	a;
	t_pile	b;
	int		*result;
	int		size;

	if (ac < 2)
		return (write(1, "Error\n", 6), 1);
	result = args_to_int(av, ac, &size);
	if (!result)
		return (1);
	if (!already_sorted(result))
		return (0);
	init_piles(&a, &b, result, size);
	algo_sorting(&a, &b);
	free(result);
	free_piles(&a, &b);
	return (0);
}
