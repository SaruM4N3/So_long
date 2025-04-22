/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:34:45 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/22 20:32:27 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/map.h"
#include "../headers/so_long.h"

static void	row_checker(t_map *map, int y, char *row, int firstrowlenght)
{
	int		x;
	size_t	i;

	x = 0;
	i = 0;
	map->grid[y] = malloc(sizeof(char) * (map->width + 1));
	while (row[x] && (row[x] != '\n'))
	{
		while (MAP_POSSIBLECHAR[i])
		{
			if ((row[x] != MAP_POSSIBLECHAR[i]))
				i++;
			else
				break ;
		}
		if (i < ft_strlen(MAP_POSSIBLECHAR))
		{
			map->grid[y][x] = row[x];
			x++;
			i = 0;
		}
		else
		{
			print_custom_error("Loading map", ERRMAPCHAR);
			return ;
		}
	}
	map->grid[y][x] = '\0';
	map->width = x;
	if (map->width != firstrowlenght)
		print_custom_error("Loading map", ERRMAPISNOTRECT);
}

static int	map_check(int fd, t_map *map)
{
	char	*row;
	int		y;
	int		firstrowlenght;

	y = 0;
	firstrowlenght = 0;
	row = "";
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	while (y < map->height)
	{
		row = get_next_line(fd);
		if (!row)
			return (-1);
		if (firstrowlenght == 0)
			firstrowlenght = ft_strlen(row) - 1;
		if (!ft_strchr(row, '\n'))
			map->width = ft_strlen(row);
		else
			map->width = ft_strlen(row) - 1;
		row_checker(map, y, row, firstrowlenght);
		map->grid[y] = row;
		y++;
	}
	map->grid[y] = NULL;
	return (0);
}

bool	get_element_pos_and_coins_nb(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->grid[j])
	{
		while (map->grid[j][i])
		{
			if (map->grid[j][i] == 'C')
				map->coins_nb++;
			if (map->grid[j][i] == MAP_EXIT)
			{
				map->exit_pos.x = i;
				map->exit_pos.y = j;
			}
			if (map->grid[j][i] == MAP_PLAYERSTART)
			{
				map->player_pos.x = i;
				map->player_pos.y = j;
				return (true);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (false);
}
static int	reset_gnl_and_get_map_height(t_map *map)
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

int	init_map(char *path, t_gameenv *env)
{
	int	fd;

	// WIP: secure mappath
	env->map.path = path;
	if (reset_gnl_and_get_map_height(&env->map))
		return (0);
	fd = open(env->map.path, O_RDONLY);
	if (fd < 0)
		return (0);
	map_check(fd, &env->map);
	close(fd);
	get_element_pos_and_coins_nb(&env->map);
	return (1);
}
