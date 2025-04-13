/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saru <saru@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 13:51:23 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/07 16:53:51 by saru             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_H
# define CELL_H

#include "texture.h"

typedef struct s_cell
{
	int	x;	
	int	y;
	t_texture texture;

	struct s_cell	*left_neighbour;
	struct s_cell	*right_neighbour;
	struct s_cell	*up_neighbour;
	struct s_cell	*down_neighbour;
} t_cell;

#endif