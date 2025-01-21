/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufalzone <ufalzone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:22:44 by ufalzone          #+#    #+#             */
/*   Updated: 2025/01/21 19:32:19 by ufalzone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_number
{
	int				value;
	int				index;
	struct s_number	*next;
	struct s_number	*prev;
}					t_number;

typedef struct s_pile
{
	struct s_number	*top;
	int				size;
}					t_pile;


#endif
