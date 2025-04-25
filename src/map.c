/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:34:45 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/25 21:42:17 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/map.h"
#include "../headers/so_long.h"

static void	row_checker(t_map *map, int y, char *row)
{
	int	x;

	map->width = 0;
	while (row[map->width])
		++map->width;
	x = 0;
	map->grid[y] = malloc(sizeof(char) * (map->width + 1));
	if (!map->grid[y])
		return ;
	while (row[x] && (row[x] != '\n'))
	{
		map->grid[y][x] = row[x];
		x++;
	}
	map->grid[y][x] = '\0';
}

static bool	map_check(int fd, t_gameenv *env)
{
	char	*row;
	int		y;

	y = 0;
	env->map.grid = malloc(sizeof(char *) * (env->map.height + 1));
	if (!env->map.grid)
		return (false);
	while (y < env->map.height)
	{
		row = get_next_line(fd);
		if (!row)
			return (false);
		row_checker(&env->map, y, row);
		env->map.grid[y] = row;
		y++;
	}
	env->map.grid[y] = NULL;
	return (true);
}

void	set_element_pos_and_coins_nb(t_gameenv *env)
{
	int	y;
	int	x;

	y = -1;
	env->map.coins_nb = 0;
	while (env->map.grid[++y])
	{
		x = -1;
		while (env->map.grid[y][++x])
		{
			if (env->map.grid[y][x] == 'C')
				env->map.coins_nb++;
			if (env->map.grid[y][x] == MAP_EXIT)
			{
				env->map.exit_pos.x = x;
				env->map.exit_pos.y = y;
			}
			if (env->map.grid[y][x] == MAP_PLAYERSTART)
			{
				set_player_pos(&env->player, x, y);
				env->map.player_pos.x = x;
				env->map.player_pos.y = y;
			}
		}
	}
}

static bool	reset_gnl_and_set_map_height(t_map *map)
{
	int	fd;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
	{
		print_error_and_return(ERRNOVALIDMAPPATH);
		return (false);
	}
	map->height = 0;
	map->width = 0;
	while (get_next_line(fd))
		map->height++;
	close(fd);
	return (true);
}

bool	init_map(t_gameenv *env)
{
	int	fd;

	if (!reset_gnl_and_set_map_height(&env->map))
		return (false);
	fd = open(env->map.path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (false);
	}
	if (!map_check(fd, env))
	{
		close(fd);
		return (false);
	}
	close(fd);
	if (!map_parsing_check(env))
		return (false);
	set_element_pos_and_coins_nb(env);
	if (env->map.coins_nb < 1)
		return (print_error_and_return(ERRMAPCOIN));
	if (check_for_valid_path(env))
		return (print_error_and_return(ERRNOVALIDPATH));
	return (true);
}
