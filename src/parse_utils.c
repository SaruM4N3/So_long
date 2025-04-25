/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:31:25 by saru              #+#    #+#             */
/*   Updated: 2025/04/25 18:46:24 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/map.h"
#include "../headers/so_long.h"

static void	fill(char **tab, t_2dvector size, t_2dvector cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_2dvector){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_2dvector){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_2dvector){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_2dvector){cur.x, cur.y + 1}, to_fill);
}

static void	flood_fill(char **tab, t_2dvector size, t_2dvector begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

static char	**grid_duplicate(t_gameenv *env)
{
	int		y;
	int		x;
	char	**dup;

	y = -1;
	if (!(dup = malloc(sizeof(char *) * (env->map.height + 1))))
		return (NULL);
	while (env->map.grid[++y])
	{
		if (!(dup[y] = malloc(sizeof(char) * (env->map.width + 1))))
		{
			while (--y >= 0)
				free(dup[y]);
			free(dup);
			return (NULL);
		}
		x = -1;
		while (env->map.grid[y][++x])
			dup[y][x] = env->map.grid[y][x];
		dup[y][x] = '\0';
	}
	dup[y] = NULL;
	return (dup);
}

static int	check_neighbours(char **grid, t_2dvector pos, char to_check)
{
	if (grid[pos.y - 1][pos.x] == to_check || grid[pos.y + 1][pos.x] == to_check
		|| grid[pos.y][pos.x - 1] == to_check || grid[pos.y][pos.x
		+ 1] == to_check)
		return (true);
	return (false);
}

int	check_for_valid_path(t_gameenv *env)
{
	char	**grid;
	int		y;
	int		x;

	if (!(grid = grid_duplicate(env)))
		return (false);
	flood_fill(grid, (t_2dvector){env->map.height, env->map.width},
			env->player.pos);
	y = -1;
	while (grid[++y])
	{
		x = -1;
		while (grid[y][++x])
		{
			if (grid[y][x] == 'P' || grid[y][x] == 'C' || grid[y][x] == 'E')
			{
				if (!check_neighbours(grid, (t_2dvector){y, x}, 'F'))
					return (false);
			}
		}
	}
	return (true);
}
