/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:49:39 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/20 14:04:39 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	init_textures(t_gameenv *env)
{
	env->img->img.height = 32;
	env->img->img.width = 32;
	env->img->img.ground = "./ressources/textures/ground32.xpm";
	env->img->img.wall = "./ressources/textures/wall32.xpm";
	env->img->img.coin = "./ressources/textures/cat32.xpm";
	env->img->img.player = "./ressources/textures/player32.xpm";
	env->img->img.exit = "./ressources/textures/exit32.xpm";
	env->img->img.img->img_wall = mlx_xpm_file_to_image(env->mlx_ptr, env->img->img.wall,
			&(env->img->img.width), &(env->img->img.height));
	env->img->img.img->img_floor = mlx_xpm_file_to_image(env->mlx_ptr, env->img->img.floor,
			&(env->img->img.width), &(env->img->img.height));
	env->img->img.img->img_exit = mlx_xpm_file_to_image(env->mlx_ptr, env->img->img.exit,
			&(env->img->img.width), &(env->img->img.height));
	env->img->img.img->img_collect = mlx_xpm_file_to_image(env->mlx_ptr,
			env->img->img.collect, &(env->img->img.width), &(env->img->img.height));
	env->img->img.img->img_player = mlx_xpm_file_to_image(env->mlx_ptr,
			env->img->img.player, &(env->img->img.width), &(env->img->img.height));
}

void    render_textures(t_gameenv env)
{
    
}

int	clean_render(t_gameenv *env)
{
	int		i;

	i = 0;
	if (env->grid != NULL)
	{
		while (env->grid[i] != NULL)
		{
			free(env->grid[i]);
			i++;
		}
		free(env->grid);
		mlx_destroy_image(env->mlx_ptr, env->img->img.img_wall);
		mlx_destroy_image(env->mlx_ptr, env->img->img.img_ground);
		mlx_destroy_image(env->mlx_ptr, env->img->img.img_coin);
		mlx_destroy_image(env->mlx_ptr, env->img->img.img_player);
		mlx_destroy_image(env->mlx_ptr, env->img->img.img_exit);
		mlx_destroy_window(env->mlx_ptr, env->mlx_win);
	}
	mlx_destroy_display(env->mlx_ptr);
	free(env->mlx_ptr);
	exit(0);
}