/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:58:57 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/27 14:08:30 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/map.h"
#include "../headers/my_mlx.h"
#include "../headers/so_long.h"

void	close_env(t_gameenv *env)
{
	if (env->map.grid)
		free_2d(env->map.grid, true);
	if (env->img.img_ground)
		mlx_destroy_image(env->mlx_ptr, env->img.img_ground);
	if (env->img.img_wall)
		mlx_destroy_image(env->mlx_ptr, env->img.img_wall);
	if (env->img.img_collect)
		mlx_destroy_image(env->mlx_ptr, env->img.img_collect);
	if (env->img.img_player)
		mlx_destroy_image(env->mlx_ptr, env->img.img_player);
	if (env->img.img_player_exit)
		mlx_destroy_image(env->mlx_ptr, env->img.img_player_exit);
	if (env->img.img_exit)
		mlx_destroy_image(env->mlx_ptr, env->img.img_exit);
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
	mlx_get_screen_size(env->mlx_ptr, &env->width, &env->height);
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

static int	init_all(t_gameenv *env)
{
	if (!init_env(env))
		return (1);
	if (!init_map(env))
	{
		close_env(env);
		return (1);
	}
	env->player = init_player(env->map.player_pos.x, env->map.player_pos.y, env);
	if (init_img_from_xpm(env))
	{
		close_env(env);
		return (print_error_and_return(ERRTEXTURE) + 1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_gameenv	env;

	env = (t_gameenv){0};
	if (ac != 2)
		return (print_error_and_return(ERRNOMAP) + 1);
	if (!ft_strnstr(av[1], ".ber\0", ft_strlen(av[1]) + 1))
		return (print_error_and_return(ERRMAPPATH));
	else
		env.map.path = av[1];
	if (init_all(&env))
		return (1);		
	mlx_loop_hook(env.mlx_ptr, &handle_no_event, &env);
	mlx_key_hook(env.win_ptr, &handle_input, &env);
	mlx_hook(env.win_ptr, DestroyNotify, StructureNotifyMask, &mlx_loop_end,
			env.mlx_ptr);
	mlx_loop(env.mlx_ptr);
	close_env(&env);
	return (0);
}
