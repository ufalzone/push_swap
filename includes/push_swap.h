/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:50 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/14 18:31:21 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "struct.h"
# include "operations.h"
# include "../libft/includes/libft.h"
# include <stdio.h>

/*
*   Parsing
*/

int	check_all(char **str);
int	*args_to_int(char **av, int ac);
int	already_sorted(int *array);

/*
*   Init
*/

void init_piles(t_pile *a, t_pile *b, int *tab, int size);
void rank_init(t_pile *a);
void display_piles(t_pile *a, t_pile *b);
/*
*   Algo
*/

void    sort_3(t_pile *a);
void    sort_5(t_pile *a, t_pile *b);
void    sort_big(t_pile *a, t_pile *b);
void    algo(t_pile *a, t_pile *b);
int     target_pos_b(t_pile *a, t_pile *b);
void    execute_rotations(t_pile *a, t_pile *b, int best_pos_a, int best_pos_b);
#endif
