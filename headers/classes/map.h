/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:04:34 by sarunomane        #+#    #+#             */
/*   Updated: 2025/02/22 16:10:23 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "cell.h"

# define MAP_POSSIBLECHAR "01PEC"
# define MAP_WALKABLE "0"
# define MAP_WALL "1"
# define MAP_PLAYERSTART "P"
# define MAP_EXIT "E"
# define MAP_COIN "C"

typedef struct s_map
{
	char	*grid;
	int		width;
	int		height;
	int		pstart;
	int		exit;
	int		*coins;
	t_cell	**cells;
	
} t_map;

void	map_check(int fd, t_map *map);
void	map_load(t_map *map, char *map_path);

#endif