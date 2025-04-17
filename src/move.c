/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:24:11 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/18 00:30:18 by zsonie           ###   ########.fr       */
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

int	move_up(t_player player, t_map map)
{
	__builtin_printf("%s", "Move Up\n");
	if (map.grid[player.pos_y - 1][player.pos_x] == '0')
	{
		player.pos_y -= 1;
		move_count();
	}
	return (0);
}

int	move_left(t_player player, t_map map)
{
	__builtin_printf("%s", "Move Left\n");
	if (map.grid[player.pos_y][player.pos_x - 1] == '0')
	{
		player.pos_x -= 1;
		move_count();
	}
	return (0);
}

int	move_down(t_player player, t_map map)
{
	__builtin_printf("%s", "Move Down\n");
	if (map.grid[player.pos_y + 1][player.pos_x] == '0')
	{
		player.pos_y += 1;
		move_count();
	}
	return (0);
}

int	move_right(t_player player, t_map map)
{
	__builtin_printf("%s", "Move Right\n");
	if (map.grid[player.pos_y][player.pos_x + 1] == '0')
	{
		player.pos_x += 1;
		move_count();	
	}	
	return (0);
}
