/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:49:39 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/29 15:16:59 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	set_path_and_size(t_gameenv *env)
{
	env->img.height = 32;
	env->img.width = 32;
	env->img.ground_path = "./textures/ground32.xpm";
	env->img.wall_path = "./textures/wall32.xpm";
	env->img.coin_path = "./textures/cat32.xpm";
	env->img.player_path = "./textures/player32.xpm";
	env->img.player_exit_path = "./textures/player_exit.xpm";
	env->img.exit_path = "./textures/exit32.xpm";
}

static int texture_check_and_init(t_gameenv *env, void **img, char *path)
{
	int check;

	check = open(path, O_RDONLY);
	if (check < 0)
		return (1);
	*img = mlx_xpm_file_to_image(env->mlx_ptr, path,
		&(env->img.width), &(env->img.height));
	if (!img)
		return (1);
	close(check);
	return (0);
}

int	init_img_from_xpm(t_gameenv *env)
{
	set_path_and_size(env);
	if (texture_check_and_init(env, &env->img.img_wall, env->img.wall_path))
		return (1);
	if (texture_check_and_init(env, &env->img.img_ground, env->img.ground_path))
		return (1);
	if (texture_check_and_init(env, &env->img.img_exit, env->img.exit_path))
		return (1);
	if (texture_check_and_init(env, &env->img.img_collect, env->img.coin_path))
		return (1);
	if (texture_check_and_init(env, &env->img.img_player, env->img.player_path))
		return (1);
	if (texture_check_and_init(env, &env->img.img_player_exit,
		 env->img.player_exit_path))
		return (1);
	return (0);
}

int	clean_render(t_gameenv *env)
{
	int	i;

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
	mlx_destroy_display(env->mlx_ptr);
	free(env->mlx_ptr);
	exit(0);
}

int	render_img(t_gameenv *env)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	if (!env->mlx_ptr || !env->win_ptr)
	{
		ft_printf("Error: Invalid MLX or window pointer\n");
		return (1);
	}
	while (env->map.grid[++y])
	{
		x = -1;
		while (env->map.grid[y][++x])
		{
			render_other_img(env, y, x);
			render_player_img(env, y, x);
		}
	}
	return (0);
}
