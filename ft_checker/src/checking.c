/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:10:56 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 20:06:09 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	read_instructions(t_list **list)
{
	char	*line;
	t_list	*node;

	line = get_next_line(0);
	if (!line)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (line)
	{
		node = ft_lstnew(line);
		if (!node)
		{
			free(line);
			ft_lstclear(list, free);
			return ;
		}
		ft_lstadd_back(list, node);
		line = get_next_line(0);
	}
}

int	apply_instruction(char *instruction, t_pile *a, t_pile *b)
{
	if (ft_strcmp(instruction, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(instruction, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(instruction, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(instruction, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(instruction, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instruction, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(instruction, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(instruction, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instruction, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(instruction, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(instruction, "rrr\n") == 0)
		rrr(a, b);
	else
		return (0);
	return (1);
}

void	execute_instructions(t_list *instructions, t_pile *a, t_pile *b)
{
	while (instructions)
	{
		if (!apply_instruction(instructions->content, a, b))
		{
			write(2, "Error\n", 6);
			ft_lstclear(&instructions, free);
			exit(1);
		}
		instructions = instructions->next;
	}
}

//Parcourir la liste et verifier a la fin que tout est bon
//Si oui, return OK
//Sinon, return KO
int	is_sort(t_pile *a, t_pile *b)
{
	t_number	*current;
	int			i;

	current = a->top;
	i = 0;
	if (b->size > 0)
		return (0);
	while (i < a->size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

void	checking(t_pile *a, t_pile *b)
{
	t_list	*instructions;

	instructions = NULL;
	read_instructions(&instructions);
	execute_instructions(instructions, a, b);
	if (is_sort(a, b) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&instructions, free);
}
