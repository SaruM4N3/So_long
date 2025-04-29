/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:34:45 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/29 15:17:11 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/map.h"
#include "../headers/so_long.h"
#include <errno.h>

static bool	init_grid(int fd, t_gameenv *env)
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
		env->map.width = ft_strlen(row);
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
	int		fd;
	char	*line;

	fd = open(map->path, O_RDONLY);
	if (fd < 0)
	{
		print_error_and_return(ERRNOVALIDMAPPATH);
		return (false);
	}
	map->height = 0;
	errno = 0;
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (errno != 0)
		return (false);
	return (true);
}

bool	init_map(t_gameenv *env)
{
	int	fd;

	if (!reset_gnl_and_set_map_height(&env->map))
		return (false);
	fd = open(env->map.path, O_RDONLY);
	if (fd < 0)
		return (false);
	if (!init_grid(fd, env))
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
	if (!check_for_valid_path(env))
		return (print_error_and_return(ERRNOVALIDPATH));
	return (true);
}
