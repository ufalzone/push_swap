/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:47:46 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/17 15:05:17 by ufalzone         ###   ########.fr       */
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
	int target_pos;
	int best_pos;
	int min_value;
	int max_value;
	int rotation_desc_a;
	int rotation_desc_b;
} t_pile;

//test
t_pile *init_pile(void);
t_number *create_number(int value);
void add_front(t_pile *pile, t_number *new_number);
void display_pile(t_pile *pile);
void free_pile(t_pile *pile);
void test_piles(void);
int target_pos(t_pile *a, t_pile *b);

#endif
