/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:49:32 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/08 19:52:11 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void init_piles(t_pile *a, t_pile *b, int *tab, int size)
{
    a->top = init_numbers(tab, size - 1);
    a->size = size - 1;
    b->top = NULL;
    b->size = 0;
}