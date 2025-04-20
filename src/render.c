/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:49:39 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/21 01:22:40 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void set_path_and_size(t_gameenv *env)
{
	env->img.height = 32;
	env->img.width = 32;
	env->img.ground_path = "./ressources/textures/ground32.xpm";
	env->img.wall_path = "./ressources/textures/wall32.xpm";
	env->img.coin_path = "./ressources/textures/cat32.xpm";
	env->img.player_path = "./ressources/textures/player32.xpm";
	env->img.exit_path = "./ressources/textures/exit32.xpm";
}


int	init_img_from_xpm(t_gameenv *env)
{
	set_path_and_size(env);
	env->img.img_wall = mlx_xpm_file_to_image(env->mlx_ptr, env->img.wall_path,
			&(env->img.width), &(env->img.height));
	if (!env->img.img_wall)
		return (1);
	env->img.img_ground = mlx_xpm_file_to_image(env->mlx_ptr, env->img.ground_path,
			&(env->img.width), &(env->img.height));
	if (!env->img.img_ground)
		return (1);
	env->img.img_exit = mlx_xpm_file_to_image(env->mlx_ptr, env->img.exit_path,
			&(env->img.width), &(env->img.height));
	if (!env->img.img_exit)
		return (1);
	env->img.img_collect = mlx_xpm_file_to_image(env->mlx_ptr, env->img.coin_path,
			&(env->img.width), &(env->img.height));
	if (!env->img.img_collect)
		return (1);
	env->img.img_player = mlx_xpm_file_to_image(env->mlx_ptr, env->img.player_path,
			&(env->img.width), &(env->img.height));
	if (!env->img.img_player)
		return (1);
	return (0);
}

void	clean_render(t_gameenv *env)
{
	int		i;

	i = 0;
	if (env->map.grid != NULL)
	{
		while (env->map.grid[i] != NULL)
		{
			free(env->map.grid[i]);
			i++;
		}
		free(env->map.grid);
		mlx_destroy_image(env->mlx_ptr, env->img.img_wall);
		mlx_destroy_image(env->mlx_ptr, env->img.img_ground);
		mlx_destroy_image(env->mlx_ptr, env->img.img_collect);
		mlx_destroy_image(env->mlx_ptr, env->img.img_player);
		mlx_destroy_image(env->mlx_ptr, env->img.img_exit);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	}
	if (env->mlx_ptr != NULL)
	{
		mlx_destroy_display(env->mlx_ptr);
		free(env->mlx_ptr);
	}
}

int		render_img(t_gameenv env)
{
	int x;
	int y;

	y = 0;
	while (env.map.grid[y])
	{
		ft_printf("%s", env.map.grid[y]);
		x = 0;
		while (env.map.grid[y][x])
		{
			if (env.map.grid[y][x] == '1')
				mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_wall, x * env.img.width, y * env.img.height);
			else if (env.map.grid[y][x] == '0')
				mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ground, x * env.img.width, y * env.img.height);
			else if (env.map.grid[y][x] == 'C')
				mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_collect, x * env.img.width, y * env.img.height);
			else if (env.map.grid[y][x] == 'P')
				mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_player, x * env.img.width, y * env.img.height);
			else if (env.map.grid[y][x] == 'E')
				mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_exit, x * env.img.width, y * env.img.height);
			x++;
		}
		y++;
	}
	return (0);
}
