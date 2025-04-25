/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:34:45 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/25 15:44:23 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/map.h"
#include "../headers/so_long.h"

static void	row_checker(t_map *map, int y, char *row)
{
	int		x;

	x = 0;
	map->grid[y] = malloc(sizeof(char) * (map->width + 1));
	while (row[x] && (row[x] != '\n'))
	{
		map->grid[y][x] = row[x];
		x++;
	}
	map->grid[y][x] = '\0';
	map->width = x;
}

static int	map_check(int fd, t_map *map)
{
	char	*row;
	int		y;

	y = 0;
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	while (y < map->height)
	{
		row = get_next_line(fd);
		if (!row)
			return (-1);
		row_checker(map, y, row);
		map->grid[y] = row;
		y++;
	}
	map->grid[y] = NULL;
	return (0);
}

void	set_element_pos_and_coins_nb(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (map->grid[++x])
	{
		while (map->grid[x][++y])
		{
			if (map->grid[x][y] == 'C')
				map->coins_nb++;
			if (map->grid[x][y] == MAP_EXIT)
			{
				map->exit_pos.x = y;
				map->exit_pos.y = x;
			}
			if (map->grid[x][y] == MAP_PLAYERSTART)
			{
				map->player_pos.x = y;
				map->player_pos.y = x;
			}
		}
		y = 0;
	}
}
static int	reset_gnl_and_set_map_height(t_map *map)
{
	int	fd;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd))
		map->height++;
	close(fd);
	return (0);
}

int	init_map(t_gameenv *env)
{
	int	fd;

	if (reset_gnl_and_set_map_height(&env->map))
		return (0);
	fd = open(env->map.path, O_RDONLY);
	if (fd < 0)
		return (0);
	map_check(fd, &env->map);
	close(fd);
	if(!map_parsing_check(env))
		return (0);
	set_element_pos_and_coins_nb(&env->map);
	return (1);
}
