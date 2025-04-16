/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:04:56 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/16 23:41:58 by zsonie           ###   ########.fr       */
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
		move_up();
	if (key == XK_a)
		move_left();
	if (key == XK_s)
		move_down();
	if (key == XK_d)
		move_right();
	return (0);
}
int	handle_no_event()
{
	return (0);		
}
