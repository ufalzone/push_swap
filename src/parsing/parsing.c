/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:32:05 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 17:21:34 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


static char	*join_args(char **av, int ac)
{
	char	*str;
	char	*tmp;
	int		i;

	if (ac == 2)
		return (ft_strdup(av[1]));
	str = ft_strdup("");
	i = 1;
	while (i < ac)
	{
		tmp = str;
		str = ft_strjoin(str, av[i]);
		free(tmp);
		if (av[i] == NULL || av[i][0] == '\0' || av[i][0] == ' ')
			return (NULL);
		if (i < ac - 1)
		{
			tmp = str;
			str = ft_strjoin(str, " ");
			free(tmp);
		}
		i++;
	}
	return (str);
}

int	*args_to_int(char **av, int ac, int *size)
{
	char	**split;
	char	*str;
	int		*result;
	int		i;
	int		count;

	str = join_args(av, ac);
	if (!str)
		return (free(str), write(1, "Error\n", 6), NULL);
	split = ft_split(str, ' ');
	free(str);
	if (!split || check_all(split))
		return (free_split(split), write(1, "Error\n", 6), NULL);
	count = 0;
	while (split[count])
		count++;
	result = (int *)malloc(sizeof(int) * count);
	if (!result)
		return (write(1, "Error\n", 6), NULL);
	i = -1;
	while (split[++i])
		result[i] = ft_atoi(split[i]);
	*size = i;
	free_split(split);
	return (result);
}

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
