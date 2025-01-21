/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:36:33 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 18:41:30 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	calculate_cost_desc(int position, t_pile *pile)
{
	if (position > pile->size / 2)
		return (-(pile->size - position));
	return (position);
}
