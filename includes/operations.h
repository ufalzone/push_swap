/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:36:45 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/06 18:38:09 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

/*
*   Swap
*/ 
void sa(t_pile *a, int is_ss);
void sb(t_pile *b, int is_ss);
void ss(t_pile *a, t_pile *b);

/*
*   Push
*/ 
void pa(t_pile *a, t_pile *b);
void pb(t_pile *a, t_pile *b);

/*
*   Rotate
*/ 
void ra(t_pile *a, t_pile *b, int is_rr);
void rb(t_pile *a, t_pile *b, int is_rr);
void rr(t_pile *a, t_pile *b);

/*
*   Reverse rotate
*/ 
void rra(t_pile *a, t_pile *b, int is_rrr);
void rrb(t_pile *a, t_pile *b, int is_rrr);
void rrr(t_pile *a, t_pile *b);