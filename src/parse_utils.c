/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:31:25 by saru              #+#    #+#             */
/*   Updated: 2025/04/25 20:42:04 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/map.h"
#include "../headers/so_long.h"

static void	fill(char **tab, t_2dvector size, t_2dvector cur, char to_fill)
{
	__builtin_printf("fill:cursor(x=%d, y=%d)\n", cur.x, cur.y);
	__builtin_printf("fill:size(x=%d, y=%d)\n", size.x, size.y);
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)  //FIXME: Either > or >= ?
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_2dvector){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_2dvector){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_2dvector){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_2dvector){cur.x, cur.y + 1}, to_fill);
}

static void	flood_fill(char **tab, t_2dvector size, t_2dvector begin)
{
	fill(tab, size, begin, '0');
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
	//while (env->map.grid[++y])
	{
		dup[y] = malloc(sizeof(char) * (env->map.width + 1));
		if (!dup)
		{
			while (--y >= 0)
				free(dup[y]);
			free(dup);
			return (NULL);
		}
		x = -1;
		while (++x < env->map.width)
		//while (env->map.grid[y][++x])
			dup[y][x] = env->map.grid[y][x];
		//dup[y][x] = '\0';
	}
	//dup[y] = NULL;
	return (dup);
}

static int	check_neighbours(t_gameenv *env, char **grid, t_2dvector pos, char to_check)
{
	__builtin_printf("fill:pos(x=%d, y=%d)\n", pos.x, pos.y);
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

	if (!(grid = grid_duplicate(env)))
		return (false);
	flood_fill(grid, (t_2dvector){env->map.width, env->map.height},
			env->player.pos);
	y = -1;
	while (++y < env->map.height)
	{
		x = -1;
		while (++x < env->map.width)
		{
			if (grid[y][x] == 'P' || grid[y][x] == 'C' || grid[y][x] == 'E')
			{
				if (!check_neighbours(env, grid, (t_2dvector){x, y}, 'F'))
					return (false);
			}
		}
	}
	return (true);
}
