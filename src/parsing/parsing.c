/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:32:05 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/08 19:08:31 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int *parsing(char *av, int ac, t_pile *a, t_pile *b)
{
    char **split;
    int *result;
    int i;
    
    (void)a;
    (void)b;
    split = ft_split(av, ' ');
    if (!split)
        return (write(1, "Error\n", 6), NULL);
    result = (int *)malloc(sizeof(int) * ac);
    if (!result)
        return (write(1, "Error\n", 6), NULL);
    if (check_all(split))
        return (write(1, "Error\n", 6), NULL);
    i = -1;
    while (split[++i])
        result[i] = ft_atoi(split[i]);
    free_split(split);
    return (result);
}

int main(int ac, char **av)
{
    if (ac <= 2)
        return (write(1, "Error\n", 6), 1);
    t_pile a;
    t_pile b;

    //parsing(av[1], ac, &a, &b);
    int *result = parsing(av[1], ac, &a, &b);
    if (result)
    {
        int i = 0;
        while (i < ac - 1)
        {
            ft_printf("%d ", result[i]);
            i++;
        }
        ft_printf("\n");
        free(result);
    }
    
}