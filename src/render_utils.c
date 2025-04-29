/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:49:39 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/29 15:48:03 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	init_player_img_from_xpm(t_gameenv *env)
{
	env->img.img_player_exit = mlx_xpm_file_to_image(env->mlx_ptr,
			env->img.player_exit_path, &(env->img.width), &(env->img.height));
	if (!env->img.img_player_exit)
	{
		mlx_destroy_image(env->mlx_ptr, env->img.img_player_exit);
		return (1);
	}
	env->img.img_player = mlx_xpm_file_to_image(env->mlx_ptr,
			env->img.player_path, &(env->img.width), &(env->img.height));
	if (!env->img.img_player)
	{
		mlx_destroy_image(env->mlx_ptr, env->img.img_player);
		return (1);
	}
	return (0);
}

void	render_player_img(t_gameenv *env, int y, int x)
{
	if (env->map.grid[y][x] == 'P')
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_player,
			x * env->img.width, y * env->img.height);
	else if (env->map.grid[y][x] == 'E' &&
			env->player.pos.x == env->map.exit_pos.x &&
			env->player.pos.y == env->map.exit_pos.y)
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,
			env->img.img_player_exit, x * env->img.width, y
			* env->img.height);
}

void	render_other_img(t_gameenv *env, int y, int x)
{
	if (env->map.grid[y][x] == '1')
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_wall, x
			* env->img.width, y * env->img.height);
	else if (env->map.grid[y][x] == '0')
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ground,
			x * env->img.width, y * env->img.height);
	else if (env->map.grid[y][x] == 'C')
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr,
			env->img.img_collect, x * env->img.width, y * env->img.height);
	else if (env->map.grid[y][x] == 'E')
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_exit, x
			* env->img.width, y * env->img.height);
}
