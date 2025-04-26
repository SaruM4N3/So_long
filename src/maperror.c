/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maperror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:37 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/26 03:43:44 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/map.h"
#include "../headers/so_long.h"

static int	check_for_player_and_exit(t_gameenv *env)
{
	int	exitcount;
	int	playercount;
	int	y;
	int	x;

	y = -1;
	x = -1;
	exitcount = 0;
	playercount = 0;
	while (env->map.grid[++y])
	{
		while (env->map.grid[y][++x])
		{
			if (env->map.grid[y][x] == 'P')
				playercount++;
			if (env->map.grid[y][x] == 'E')
				exitcount++;
		}
		x = 0;
	}
	if (playercount != 1)
		return (ERRMAPPLAYER);
	if (exitcount != 1)
		return (ERRMAPEXIT);
	return (1);
}

static int	check_for_map_char(t_gameenv *env)
{
	int	y;
	int	x;

	y = -1;
	while (env->map.grid[++y])
	{
		x = -1;
		while (env->map.grid[y][++x] && (env->map.grid[y][x] != '\n'))
		{
			if (env->map.grid[y][x] == MAP_POSSIBLECHAR[0] ||
				env->map.grid[y][x] == MAP_POSSIBLECHAR[1] ||
				env->map.grid[y][x] == MAP_POSSIBLECHAR[2] ||
				env->map.grid[y][x] == MAP_POSSIBLECHAR[3] ||
				env->map.grid[y][x] == MAP_POSSIBLECHAR[4])
				continue ;
			else
				return (ERRMAPCHAR);
		}
	}
	return (1);
}

static int	check_for_map_rect(t_gameenv *env)
{
	int	y;
	int	x;
	int	width;

	y = -1;
	width = (ft_strlen(env->map.grid[0]) - 1);
	while (env->map.grid[++y])
	{
		x = 0;
		while (env->map.grid[y][x] && env->map.grid[y][x] != '\n')
			x++;
		if (x != width)
			return (ERRMAPISNOTRECT);
	}
	return (1);
}

static int	check_for_wall(t_gameenv *env)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (env->map.grid[++y])
	{
		x = -1;
		ft_printf("");
		if (env->map.grid[y][0] != MAP_WALL ||
			env->map.grid[y][env->map.width -1] != MAP_WALL)
			return (ERRMAPWALL);
		while (env->map.grid[y][++x] && env->map.grid[y][x] != '\n')
		{
			if (env->map.grid[0][x] != MAP_WALL)
				return (ERRMAPWALL);
			if (env->map.grid[env->map.height - 1][x] != MAP_WALL)
				return (ERRMAPWALL);
		}
	}
	return (1);
}

int	map_parsing_check(t_gameenv *env)
{
	if (env->map.height < 3 || env->map.width < 3)
		return (print_error_and_return(ERRMAPSIZE));
	if (check_for_map_char(env) == ERRMAPCHAR)
		return (print_error_and_return(ERRMAPCHAR));
	else if (check_for_map_rect(env) == ERRMAPISNOTRECT)
		return (print_error_and_return(ERRMAPISNOTRECT));
	else if (check_for_wall(env) == ERRMAPWALL)
		return (print_error_and_return(ERRMAPWALL));
	else if (check_for_player_and_exit(env) == ERRMAPEXIT)
		return (print_error_and_return(ERRMAPEXIT));
	else if (check_for_player_and_exit(env) == ERRMAPPLAYER)
		return (print_error_and_return(ERRMAPPLAYER));
	return (1);
}
