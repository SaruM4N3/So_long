/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:04:34 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/26 05:06:37 by zsonie           ###   ########.fr       */
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
# define MAP_MAXSIZE 1024

# define TEST_MAP_PATH "./ressources/maps/test.ber"

# include "so_long.h"

void	set_element_pos_and_coins_nb(t_gameenv *env);
bool	init_map(t_gameenv *env);
int		check_for_valid_path(t_gameenv *env);

#endif