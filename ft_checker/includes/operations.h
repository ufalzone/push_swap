/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:45 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 19:46:55 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "struct.h"
# include <stdlib.h>
# include <unistd.h>
/*
 *   Swap
 */
void	sa(t_pile *a);
void	sb(t_pile *b);
void	ss(t_pile *a, t_pile *b);

/*
 *   Push
 */
void	pa(t_pile *a, t_pile *b);
void	pb(t_pile *a, t_pile *b);

/*
 *   Rotate
 */
void	ra(t_pile *a);
void	rb(t_pile *b);
void	rr(t_pile *a, t_pile *b);

/*
 *   Reverse rotate
 */
void	rra(t_pile *a);
void	rrb(t_pile *b);
void	rrr(t_pile *a, t_pile *b);

#endif
