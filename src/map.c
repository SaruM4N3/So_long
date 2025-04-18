/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:34:45 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/18 14:51:06 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/map.h"
#include "../headers/so_long.h"

static void	row_checker(t_map *map, int y, char *row)
{
	int	x;
	size_t	i;

	x = 0;
	i = 0;
	while (row[x] && (row[x] != '\n'))
	{
		while (MAP_POSSIBLECHAR[i])
		{
			if ((row[x] != MAP_POSSIBLECHAR[i]))
				i++;
		}
		if (i < ft_strlen(MAP_POSSIBLECHAR))
		{
			map->grid[y][x] = row[x];
			x++;
			i = 0;
		}
		else
			print_custom_error("Loading map", ERRMAPCHAR);
	}
	//Perhaps just x, but i'm not sure since im waiting for '\n'
	map->width = x - 1;
}

static int	map_check(int fd, t_map *map)
{
	char	*row;
	int		y;
	static int rowlenght;

	y = 0;
	row = "";
	while (row)
	{
		row = get_next_line(fd);
		if (!row)
			return (-1);
		rowlenght = ft_strlen(row);
		row_checker(map, y, row);
		if (map->width != rowlenght-1)
			return (print_custom_error("Loading map", ERRMAPISNOTRECT));
		if (!map->grid[y])
			map->grid[y] = row;
		else
			ft_printf("ya une couilles dans le potage");
		y++;
	}
	map->height = y;
	return (0);
}

bool	get_player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->grid[j])
	{
		while (map->grid[j][i])
		{
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

int	init_map(char *path, t_map *map)
{
	int	fd;

	//WIP: secure mappath 
	map->path = path;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		return (-1);
	map_check(fd, map);
	close(fd);
	return (0);
}
