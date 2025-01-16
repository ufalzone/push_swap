/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:45 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/14 10:23:01 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

/*
*   Swap
*/
void sa(t_pile *a);
void sb(t_pile *b);
void ss(t_pile *a, t_pile *b);

/*
*   Push
*/
void pa(t_pile *a, t_pile *b);
void pb(t_pile *a, t_pile *b);

/*
*   Rotate
*/
void ra(t_pile *a);
void rb(t_pile *b);
void rr(t_pile *a, t_pile *b);

/*
*   Reverse rotate
*/
void rra(t_pile *a);
void rrb(t_pile *b);
void rrr(t_pile *a, t_pile *b);
