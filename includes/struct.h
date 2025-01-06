/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:47:46 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/06 16:45:54 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct  s_number
{
    int value;
    int rank;
    struct s_number *next;
    struct s_number *prev;
} t_number ;

typedef struct  s_pile
{
    struct s_number *top;
    int size;
} t_pile;