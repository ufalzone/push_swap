/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:06:11 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 19:52:05 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "operations.h"
# include "../libft/includes/libft.h"

// test
t_pile				*init_pile(void);
t_number			*create_number(int value);
void				add_front(t_pile *pile, t_number *new_number);
void				display_pile(t_pile *pile);
void				test_piles(void);
int					check_all(char **str);
int					*args_to_int(char **av, int ac, int *size);
int					already_sorted(int *result);
void				init_piles(t_pile *a, t_pile *b, int *result, int size);
void				free_piles(t_pile *a, t_pile *b);
void				algo_sorting(t_pile *a, t_pile *b);
void				checking(t_pile *a, t_pile *b);
void				display_piles(t_pile *a, t_pile *b);

#endif
