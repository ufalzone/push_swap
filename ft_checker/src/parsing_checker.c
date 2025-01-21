/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:32:23 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 19:45:49 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	already_sorted(int *array)
{
	int	i;

	i = 0;
	while (array[i] && array[i + 1])
	{
		if (array[i] > array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static int	check_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][0] == '-' || str[i][0] == '+')
			j++;
		else if ((str[i][0] == '-' || str[i][0] == '+') && str[i][1] == '\0')
			return (1);
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

static int	check_intmax(char **str)
{
	long	result;
	int		i;

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

static int	check_double(char **str)
{
	int		i;
	int		j;
	long	result;

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

int	check_all(char **str)
{
	if (check_digit(str) || check_intmax(str) || check_double(str))
		return (1);
	return (0);
}
