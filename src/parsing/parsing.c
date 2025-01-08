/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:32:05 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/08 19:46:42 by ufalzone         ###   ########.fr       */
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

int main(int ac, char **av)
{
    if (ac < 2)
        return (write(1, "Error\n", 6), 1);
    t_pile a;
    t_pile b;

    int *result = args_to_int(av, ac);
    if (!result)
        return (write(1, "Error\n", 6), 1);
    init_piles(&a, &b, result, ac);
    free(result);
}