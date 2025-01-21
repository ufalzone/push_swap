/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:50 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 17:02:27 by ufalzone         ###   ########.fr       */
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
int	*args_to_int(char **av, int ac, int *size);
int	already_sorted(int *array);

/*
*   Init
*/

void init_piles(t_pile *a, t_pile *b, int *tab, int size);
void rank_init(t_pile *a);
void display_piles(t_pile *a, t_pile *b);
void free_piles(t_pile *a, t_pile *b);
/*
*   Algo
*	A to B
*/

void	sort_2_b(t_pile *b);
int	find_target_pos_b(t_number *number, t_pile *b);
void	target_pos_desc(t_pile *a, t_pile *b);
int	calculate_cost_desc(int position, t_pile *pile);
void	execute_solomove_desc(t_pile *a, t_pile *b, int target_pos_a,
		int target_pos_b);
void	execute_move_desc(t_pile *a, t_pile *b);

/*
* Algo
* B to A
*/
void	execute_move_asc(t_pile *a);
int	find_target_pos_a(t_number *number, t_pile *a);
void	sort_3_a(t_pile *a);
void	sort_2_a(t_pile *a);
void	final_sort(t_pile *a);
/*
* 	Tools
*/

void	find_max_min(t_pile *pile);


void    sort_3(t_pile *a);
void    sort_5(t_pile *a, t_pile *b);
void    sort_big(t_pile *a, t_pile *b);
void    algo_sorting(t_pile *a, t_pile *b);
int     target_pos_b(t_pile *a, t_pile *b);
void    execute_rotations(t_pile *a, t_pile *b, int best_pos_a, int best_pos_b);
void    target_pos(t_pile *a, t_pile *b);
void    test_algo_turk(t_pile *a, t_pile *b);
#endif
