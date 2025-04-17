/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:34:45 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/18 00:29:18 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/map.h"
#include "../headers/so_long.h"

static void	row_checker(t_map *map, int y, char *row)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (row[x] && row[x] != '\n')
	{
		while (row[x] != MAP_POSSIBLECHAR[i])
			i++;
		if (i <= ft_strlen(MAP_POSSIBLECHAR))
		{
			x++;
			i = 0;
		}
		else
			print_custom_error("Loading map", ERRMAPCHAR);
	}
	map->width = x;
}

void	get_player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map.grid[j])
	{
		while (map.grid[j][i])
		{
			if (map.grid[j][i] != MAP_PLAYERSTART)
			{
				map->player_pos.x = i;
				map->player_pos.y = j;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	map_check(int fd, t_map *map)
{
	char	*row;
	int		y;

	y = 0;
	row = 1;
	while (row)
	{
		row = get_next_line(fd);
		if (!row)
			return ;
		row_checker(map, y, row);
		if (!map->grid)
			map->grid = row;
		y++;
	}
	map->height = y;
}

void	map_load(t_map *map, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return ;
	map_check(fd, map);
	close(fd);
}
