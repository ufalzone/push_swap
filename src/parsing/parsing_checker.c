/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:32:23 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/08 18:22:27 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int check_digit(char **str)
{
    int i;
    int j;
        
    i = 0;
    while (str[i])
    {
        j = 0;
        if (str[i][0] == '-' || str[i][0] == '+')
            j++;
        while (str[i][j])
        {
            if (!ft_isdigit(str[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int check_intmax(char **str)
{
    long result;
    int i;

    i = 0;
    while (str[i])
    {
        result = ft_atol(str[i]);
        if (result > INT_MAX || result < INT_MIN)
            return (1);
        i++;
    }
    return (0);
}

static int check_double(char **str)
{
    int i;
    int j;

    long result;
    i = 0;
    while (str[i])
    {
        result = ft_atol(str[i]);
        j = i + 1;
        while (str[j])
        {
            if (result == ft_atol(str[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int check_all(char **str)
{
    if (check_digit(str) || check_intmax(str) || check_double(str))
        return (1);
    return (0);
}