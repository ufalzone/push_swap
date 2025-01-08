/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:45:50 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/08 18:38:25 by ufalzone         ###   ########.fr       */
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

/*
*   Init
*/

void init_piles(t_pile *a, t_pile *b, int *tab, int size);

#endif