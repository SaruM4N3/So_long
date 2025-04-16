/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:04:34 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/17 01:29:43 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MAP_POSSIBLECHAR "01PEC"
# define MAP_WALKABLE "0"
# define MAP_WALL "1"
# define MAP_PLAYERSTART "P"
# define MAP_EXIT "E"
# define MAP_COIN "C"

typedef struct s_map
{
	char	**grid;
	char	*path;
	int		width;
	int		height;
}			t_map;

void		map_check(int fd, t_map *map);
void		map_load(t_map *map);

#endif