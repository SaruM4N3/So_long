/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:02:56 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/18 14:26:54 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/map.h"

t_player init_player(int x, int y, t_gameenv *env)
{
	t_player player;

	player.pos.x = x;
	player.pos.y = y;
	env->player = player;
	return (player);
}

void set_player_pos(t_player *player,int x,int y)
{
	player->pos.x = x;
	player->pos.y = y;
}
