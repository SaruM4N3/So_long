/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:04:56 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/25 21:31:11 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/my_mlx.h"
#include "../headers/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>

int	handle_input(int key, t_gameenv *env)
{
	if (key == XK_Escape)
		mlx_loop_end(env->mlx_ptr);
	if (key == XK_w)
		move_up(&env->player, env->map);
	if (key == XK_a)
		move_left(&env->player, env->map);
	if (key == XK_s)
		move_down(&env->player, env->map);
	if (key == XK_d)
		move_right(&env->player, env->map);
	return (0);
}

bool	check_for_remaining_coins(t_gameenv *env)
{
	if (env->player.coins >= env->map.coins_nb)
		return (true);
	return (false);
}

int	handle_no_event(t_gameenv *env)
{
	render_img(env);
	if (check_for_remaining_coins(env))
	{
		if (env->player.pos.x == env->map.exit_pos.x
			&& env->player.pos.y == env->map.exit_pos.y)
			mlx_loop_end(env->mlx_ptr);
	}
	return (0);
}
