/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:04:56 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/17 21:13:55 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "../headers/so_long.h"
#include "../headers/my_mlx.h"
#include "../minilibx-linux/mlx.h"

int	handle_input(int key, t_gameenv *env)
{
	if (key == XK_Escape)
		mlx_loop_end(env->mlx_ptr);
	if (key == XK_w)
		move_up(env->player, env->map);
	if (key == XK_a)
		move_left(env->player, env->map);
	if (key == XK_s)
		move_down(env->player, env->map);
	if (key == XK_d)
		move_right(env->player, env->map);
	return (0);
}
int	handle_no_event()
{
	__builtin_printf("%s","test");
	return (0);		
}
