/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:58:57 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/14 23:44:55 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/my_mlx.h"

#include "../libft/headers/libft.h"
#include "../libft/headers/time_manager.h"

#include "../minilibx-linux/mlx.h"

bool	close_env(t_gameenv *env)
{
	if (env->win_ptr)
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	if (env->mlx_ptr)
	{
		mlx_destroy_display(env->mlx_ptr);
		free(env->mlx_ptr);
	}
	return (true);
}

bool init_env(t_gameenv *env)
{
	env->mlx_ptr = mlx_init();
	if (!env->mlx_ptr)
		return (close_env(env->mlx_ptr));
	env->width = 1920;
	env->height = 1080;
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "So_long");
	if (!env->win_ptr)
	{
		free(env->win_ptr);
		return (false);
	}
	return (true);
}

int	main(void)
{
	t_gameenv env;
	t_data	data;
	void	*grass;
	int		grass_width;
	int		grass_height;
	
	if (!init_env(&env))
		return (1);
	data.img = mlx_new_image(env.mlx_ptr, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, data.img, 0, 0);
	//test
	my_mlx_draw_tester(data);
		//ca crash ici
	grass = mlx_xpm_file_to_image(env.mlx_ptr,"../ressources/textures/grassTileset.xpm", &grass_width, &grass_height);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, grass, grass_width, grass_height);
	mlx_loop(env.mlx_ptr);
	mlx_destroy_window(env.mlx_ptr, env.win_ptr);
	mlx_destroy_image(env.mlx_ptr, data.img);
	free(env.mlx_ptr);
	return (0);
}
