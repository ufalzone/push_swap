/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:47:46 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/13 11:16:26 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <stdlib.h>
#include <unistd.h>

typedef struct  s_number
{
    int value;
    int index;
    struct s_number *next;
    struct s_number *prev;
} t_number ;

typedef struct  s_pile
{
    struct s_number *top;
    int size;
} t_pile;

#endif
