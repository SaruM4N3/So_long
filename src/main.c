/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:58:57 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/23 00:42:20 by zsonie           ###   ########.fr       */
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

static bool	init_env(t_gameenv *env)
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

int	main(int ac, char **av)
{
	t_gameenv	env;
	if (ac != 2)
	{
		ft_printf("Error\n, please proceed as follow\n\n\
<< ./so_long 'path_to_map.ber' >>\n\n\
Or test with\n\n<< ./so_long test >>\n");
		return (0);
	}
	if (ft_strncmp(av[1],"test", 8) == 0)
		env.map.path = TEST_MAP_PATH;
	else
		env.map.path = av[1];
	if (!init_env(&env))
		return (1);
	if (!init_map(env.map.path, &env))
		return (1);
	env.player = init_player(env.map.player_pos.x, env.map.player_pos.y, &env);
	init_img_from_xpm(&env);
	mlx_loop_hook(env.mlx_ptr, &handle_no_event, &env);
	mlx_key_hook(env.win_ptr, &handle_input, &env);
	mlx_hook(env.win_ptr, DestroyNotify, StructureNotifyMask, &mlx_loop_end,
			env.mlx_ptr);
	mlx_loop(env.mlx_ptr);
	close_env(&env);
}
