/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:31:25 by saru              #+#    #+#             */
/*   Updated: 2025/04/14 17:06:05 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/classes/map.h"
#include <stddef.h>

static void	flood_fill(char **grid, int x, int y, int width, int height)
{
	// Check if the current position is out of bounds or not walkable
	if (x < 0 || y < 0 || x >= width || y >= height || grid[y][x] == '1'
		|| grid[y][x] == 'F')
		return ;
	// Mark the current position as visited
	grid[y][x] = 'F';
	// Recursively flood-fill in all four directions
	flood_fill(grid, x + 1, y, width, height); // Right
	flood_fill(grid, x - 1, y, width, height); // Left
	flood_fill(grid, x, y + 1, width, height); // Down
	flood_fill(grid, x, y - 1, width, height); // Up
}

static int	validate_map(t_map *map)
{
	char	**grid_copy;
	int		coins;

	int x, y;
	coins = 0, exit_found = 0;
	// Create a copy of the map grid
	grid_copy = ft_strdup_2d(map->grid, map->height);
	// Find the player's position and start flood-fill
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (grid_copy[y][x] == 'P')
			{
				flood_fill(grid_copy, x, y, map->width, map->height);
				break ;
			}
			x++;
		}
		y++;
	}
    check_for_coins_and_exit(&map, x, y, grid_copy);    
	free_2d_array(grid_copy, map->height);
	return (coins == 0 && exit_found == 0);
}

void	check_for_coins_and_exit(t_map *map, int x, int y, char **grid_copy)
{
	// Check if all coins and the exit are reachable
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'C' && grid_copy[y][x] != 'F')
				coins++;
			if (map->grid[y][x] == 'E' && grid_copy[y][x] != 'F')
				exit_found++;
			x++;
		}
		y++;
	}
}

char	**ft_strdup_2d(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}
