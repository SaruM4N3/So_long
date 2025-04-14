/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:58:57 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/14 02:08:14 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/my_mlx.h"

#include "../libft/headers/libft.h"
#include "../libft/headers/time_manager.h"

#include "../minilibx-linux/mlx.h"


// int	close_env(t_gameenv *env)
// {
// 	if (env->win)
// 		mlx_destroy_window(env->mlx, env->win);
// 	if (env->mlx)
// 	{
// 		mlx_destroy_display(env->mlx);
// 		free(env->mlx);
// 	}
// }

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	t_data	data;
	t_coord coord;

	coord.pos_x = 100;
	coord.pos_y = 100;
	coord.target_x = 300;
	coord.target_y = 600;
	
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	mlx_win_ptr = mlx_new_window(mlx_ptr, 1920, 10800, "So_long");
	if (!mlx_win_ptr)
	{
		free(mlx_win_ptr);
		return (1);
	}
	data.img = mlx_new_image(mlx_ptr, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_put_image_to_window(mlx_ptr, mlx_win_ptr, data.img, 0, 0);
	my_mlx_draw_square(&data, &coord, 10, red);
	my_mlx_draw_square(&data, &coord, 20, green);
	my_mlx_draw_square(&data, &coord, 30, blue);
	my_mlx_draw_square(&data, &coord, 40, cyan);
	my_mlx_draw_square(&data, &coord, 50, yellow);
	my_mlx_draw_square(&data, &coord, 60, orange);
	my_mlx_draw_square(&data, &coord, 70, grey);
	my_mlx_draw_square(&data, &coord, 80, white);
	my_mlx_draw_line(&data, &coord, cyan);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, mlx_win_ptr);
	mlx_destroy_image(mlx_ptr, data.img);
	free(mlx_ptr);
	return (0);
}
