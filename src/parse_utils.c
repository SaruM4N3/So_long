/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:31:25 by saru              #+#    #+#             */
/*   Updated: 2025/04/29 22:37:30 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/map.h"
#include "../headers/so_long.h"

static void	fill(char **tab, t_2dvector size, t_2dvector cur, char to_fill)
{
	if (cur.y < 0)
		return ;
	if (cur.y > size.y)
		return ;
	if (cur.x < 0)
		return ;
	if (cur.x > size.x)
		return ;
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == 'F')
		return ;
	if (tab[cur.y][cur.x] == to_fill || tab[cur.y][cur.x] == 'C'
		|| tab[cur.y][cur.x] == 'E' )
		tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_2dvector){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_2dvector){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_2dvector){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_2dvector){cur.x, cur.y + 1}, to_fill);
}

static void	flood_fill(char **tab, int size_x, int size_y, t_2dvector begin)
{
	fill(tab, (t_2dvector){size_x, size_y}, begin, '0');
}

static char	**grid_duplicate(t_gameenv *env)
{
	int		y;
	int		x;
	char	**dup;

	y = -1;
	dup = malloc(sizeof(char *) * (env->map.height + 1));
	if (!dup)
		return (NULL);
	while (++y < env->map.height)
	{
		dup[y] = malloc(sizeof(char) * (env->map.width + 1));
		if (!dup[y])
		{
			free_2d(dup, true);
			return (NULL);
		}
		x = -1;
		while (++x < env->map.width)
			dup[y][x] = env->map.grid[y][x];
	}
	dup[y] = NULL;
	return (dup);
}

static int	check_neighbours(t_gameenv *env, char **grid, t_2dvector pos,
		char to_check)
{
	if (pos.y > 0 && grid[pos.y - 1][pos.x] == to_check)
		return (true);
	if (pos.y + 1 < env->map.height && grid[pos.y + 1][pos.x] == to_check)
		return (true);
	if (pos.x > 0 && grid[pos.y][pos.x - 1] == to_check)
		return (true);
	if (pos.x + 1 < env->map.width && grid[pos.y][pos.x + 1] == to_check)
		return (true);
	return (false);
}

int	check_for_valid_path(t_gameenv *env)
{
	char	**grid;
	int		y;
	int		x;

	grid = grid_duplicate(env);
	if (!grid)
		return (false);
	flood_fill(grid, env->map.width, env->map.height, env->player.pos);
	y = -1;
	while (++y < env->map.height)
	{
		x = -1;
		while (++x < env->map.width)
		{
			if (grid[y][x] == 'P' || grid[y][x] == 'C' || grid[y][x] == 'E')
			{
				if (!check_neighbours(env, grid, (t_2dvector){x, y}, 'F'))
					return (free_2d(grid, false));
			}
		}
	}
	return (free_2d(grid, true));
}
