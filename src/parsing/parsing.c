/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:32:05 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/13 17:16:41 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static char *join_args(char **av, int ac)
{
    char    *str;
    char    *tmp;
    int     i;

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

int *args_to_int(char **av, int ac)
{
    char    **split;
    char    *str;
    int     *result;
    int     i;
    int     count;

    str = join_args(av, ac);
    if (!str)
        return (write(1, "Error\n", 6), NULL);
    split = ft_split(str, ' ');
    free(str);
    if (!split || check_all(split))
        return (write(1, "Error\n", 6), NULL);
    count = 0;
    while (split[count])
        count++;
    result = (int *)malloc(sizeof(int) * count);
    if (!result)
        return (write(1, "Error\n", 6), NULL);
    i = -1;
    while (split[++i])
        result[i] = ft_atoi(split[i]);
    free_split(split);
    return (result);
}

#include <stdio.h>
static void display_piles(t_pile *a, t_pile *b)
{
    t_number *current_a;
    t_number *current_b;
    int i;

    printf("=== PILE A ===\n");
    printf("Size: %d\n", a->size);
    if (a->size > 0)
    {
        current_a = a->top;
        i = 0;
        do
        {
            printf("Node %d: Value = %d, Index = %d\n", i, current_a->value, current_a->index);
            current_a = current_a->next;
            i++;
        } while (current_a != a->top);
    }

    printf("\n=== PILE B ===\n");
    printf("Size: %d\n", b->size);
    if (b->size > 0)
    {
        current_b = b->top;
        i = 0;
        do
        {
            printf("Node %d: Value = %d, Index = %d\n", i, current_b->value, current_b->index);
            current_b = current_b->next;
            i++;
        } while (current_b != b->top);
    }
    printf("\n");
}

int main(int ac, char **av)
{
    if (ac <= 2)
        return (write(1, "Error\n", 6), 1);
    t_pile a;
    t_pile b;

    int *result = args_to_int(av, ac);
    if (!result)
        return (1);
    if (!already_sorted(result))
        return (0);
    init_piles(&a, &b, result, ac - 1);
	// display_piles(&a, &b);
	algo(&a, &b);
	// display_piles(&a, &b);
    free(result);
    return (0);
}

