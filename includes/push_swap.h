/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:50 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/13 13:06:23 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "struct.h"
# include "operations.h"
# include "../libft/includes/libft.h"

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

/*
*   Algo
*/

void    sort_3(t_pile *a);
void    sort_5(t_pile *a, t_pile *b);
void    sort_big(t_pile *a, t_pile *b);
void    algo(t_pile *a, t_pile *b);
int     cost_push_b(t_pile *a, t_pile *b, int *best_pos_a, int *best_pos_b);
void    execute_rotations(t_pile *a, t_pile *b, int best_pos_a, int best_pos_b);
#endif
