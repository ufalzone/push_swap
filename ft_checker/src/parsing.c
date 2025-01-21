/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:06:59 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 19:45:54 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
		return (free(str), write(2, "Error\n", 6), NULL);
	split = ft_split(str, ' ');
	free(str);
	if (!split || check_all(split))
		return (free_split(split), write(2, "Error\n", 6), NULL);
	count = 0;
	while (split[count])
		count++;
	result = (int *)malloc(sizeof(int) * count);
	if (!result)
		return (write(2, "Error\n", 6), NULL);
	i = -1;
	while (split[++i])
		result[i] = ft_atoi(split[i]);
	*size = i;
	free_split(split);
	return (result);
}
