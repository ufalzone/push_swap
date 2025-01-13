/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:59:38 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/13 11:16:50 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    rank_init(t_pile *pile)
{
    t_number    *current;
    t_number    *min;
    int         rank;
    int         first_pass;

    rank = 0;
    while (rank < pile->size)  // Pour chaque position de 0 à size-1
    {
        current = pile->top;
        min = NULL;
        first_pass = 1;
        while (first_pass || current != pile->top)  // Parcours circulaire
        {
            if (current == pile->top)
                first_pass = 0;
            if ((!min || current->value < min->value) && current->index == -1)
                min = current;  // Garde le plus petit nombre non classé
            current = current->next;
        }
        if (min)
            min->index = rank++;  // Assigne le rang actuel au plus petit trouvé
    }
}
