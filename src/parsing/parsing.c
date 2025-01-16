/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:32:05 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/14 17:16:06 by ufalzone         ###   ########.fr       */
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
void display_piles(t_pile *a, t_pile *b)
{
    static int count = 0;
    t_number *current;
    int i;

    count++;
    printf("\n=== DISPLAY #%d ===\n", count);
    printf("=== PILE A (%d) ===\n", a->size);
    if (a->size > 0)
    {
        current = a->top;
        i = 0;
        while (i < a->size)
        {
            printf("value: %d index: %d\n", current->value, current->index);
            current = current->next;
            i++;
        }
    }

    printf("\n=== PILE B (%d) ===\n", b->size);
    if (b->size > 0)
    {
        current = b->top;
        i = 0;
        while (i < b->size)
        {
            printf("value: %d index: %d\n", current->value, current->index);
            current = current->next;
            i++;
        }
    }
    printf("\n");
}
