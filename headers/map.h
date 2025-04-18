/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:04:34 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/18 14:49:47 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MAP_POSSIBLECHAR "01PEC"
# define MAP_WALKABLE '0'
# define MAP_WALL '1'
# define MAP_PLAYERSTART 'P'
# define MAP_EXIT 'E'
# define MAP_COIN 'C'

# define TEST_MAP_PATH "../ressources/maps/test.ber"

# include "so_long.h"

bool	get_player_pos(t_map *map);
int		init_map(char *path, t_map *map);

#endif