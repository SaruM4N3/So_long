/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:58:57 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/21 01:23:54 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/map.h"
#include "../headers/my_mlx.h"
#include "../headers/so_long.h"

void	close_env(t_gameenv *env)
{
	mlx_destroy_image(env->mlx_ptr, env->img.img);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_display(env->mlx_ptr);
	free(env->mlx_ptr);
}

bool	init_env(t_gameenv *env)
{
	env->mlx_ptr = mlx_init();
	if (!env->mlx_ptr)
		return (false);
	env->width = 1920;
	env->height = 1080;
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height,
			"So_long");
	if (!env->win_ptr)
	{
		mlx_destroy_display(env->mlx_ptr);
		free(env->mlx_ptr);
		return (false);
	}
	env->img.img = mlx_new_image(env->mlx_ptr, env->width, env->height);
	if (!env->img.img)
	{
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		mlx_destroy_display(env->mlx_ptr);
		free(env->mlx_ptr);
		return (false);
	}
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel,
			&env->img.line_length, &env->img.endian);
	return (true);
}

int	main(void)
{
	t_gameenv	env;

	if (!init_env(&env))
		return (1);
	if (!init_map(TEST_MAP_PATH, &env.map))
		return (1);
	env.player = init_player(env.map.player_pos.x, env.map.player_pos.y, &env);
	ft_printf("player_pos_x: %d\tplayer_pos_y: %d\n", env.player.pos.x,
			env.player.pos.y);
	if (!init_img_from_xpm(&env))
		clean_render(&env);
	ft_printf("not seg");

	mlx_loop_hook(env.win_ptr, &render_img, &env);
	ft_printf("seg");
	mlx_loop_hook(env.win_ptr, &handle_no_event, &env);
	mlx_key_hook(env.win_ptr, &handle_input, &env);
	mlx_hook(env.win_ptr, DestroyNotify, StructureNotifyMask, &mlx_loop_end,
			env.mlx_ptr);
	mlx_loop(env.mlx_ptr);
	close_env(&env);
}
