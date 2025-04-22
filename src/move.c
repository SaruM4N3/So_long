/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:24:11 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/22 20:25:44 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/map.h"
#include "../headers/so_long.h"

static int	move_count(void)
{
	static int	count = 0;

	count++;
	__builtin_printf("MoveCount : %d\n", count);
	return (count);
}

int	move_up(t_player *player, t_map map)
{
	__builtin_printf("%s", "Move Up\n");
	if (map.grid[player->pos.y - 1][player->pos.x] != '1')
	{
		if (!(map.grid[player->pos.y][player->pos.x] == 'E'))
			map.grid[player->pos.y][player->pos.x] = '0';
		player->pos.y -= 1;
		if (map.grid[player->pos.y][player->pos.x] == 'C')
		{
			player->coins++;
			map.grid[player->pos.y][player->pos.x] = 'P';
		}
		if (map.grid[player->pos.y][player->pos.x] == '0')
			map.grid[player->pos.y][player->pos.x] = 'P';
		if (map.grid[player->pos.y][player->pos.x] == 'E')
		{
			// check_for_coins();
		}
		move_count();
	}
	return (0);
}

int	move_left(t_player *player, t_map map)
{
	__builtin_printf("%s", "Move Left\n");
	if (map.grid[player->pos.y][player->pos.x - 1] != '1')
	{
		if (!(map.grid[player->pos.y][player->pos.x] == 'E'))
			map.grid[player->pos.y][player->pos.x] = '0';
		player->pos.x -= 1;
		if (map.grid[player->pos.y][player->pos.x] == 'C')
		{
			player->coins++;
			map.grid[player->pos.y][player->pos.x] = 'P';
		}
		if (map.grid[player->pos.y][player->pos.x] == '0')
		map.grid[player->pos.y][player->pos.x] = 'P';
		if (map.grid[player->pos.y][player->pos.x] == 'E')
		{
			// check_for_coins();
		}
		move_count();
	}
	return (0);
}

int	move_down(t_player *player, t_map map)
{
	__builtin_printf("%s", "Move Down\n");
	if (map.grid[player->pos.y + 1][player->pos.x] != '1')
	{
		if (!(map.grid[player->pos.y][player->pos.x] == 'E'))
			map.grid[player->pos.y][player->pos.x] = '0';
		player->pos.y += 1;
		if (map.grid[player->pos.y][player->pos.x] == 'C')
		{
			player->coins++;
			map.grid[player->pos.y][player->pos.x] = 'P';
		}
		if (map.grid[player->pos.y][player->pos.x] == '0')
		map.grid[player->pos.y][player->pos.x] = 'P';
		if (map.grid[player->pos.y][player->pos.x] == 'E')
		{
			// check_for_coins();
		}
		move_count();
	}
	return (0);
}

int	move_right(t_player *player, t_map map)
{
	__builtin_printf("%s", "Move Right\n");
	if (map.grid[player->pos.y][player->pos.x + 1] != '1')
	{
		if (!(map.grid[player->pos.y][player->pos.x] == 'E'))
			map.grid[player->pos.y][player->pos.x] = '0';
		player->pos.x += 1;
		if (map.grid[player->pos.y][player->pos.x] == 'C')
		{
			player->coins++;
			map.grid[player->pos.y][player->pos.x] = 'P';
		}
		if (map.grid[player->pos.y][player->pos.x] == '0')
		map.grid[player->pos.y][player->pos.x] = 'P';
		if (map.grid[player->pos.y][player->pos.x] == 'E')
		{
			// check_for_coins();
		}
		move_count();	
	}	
	return (0);
}
