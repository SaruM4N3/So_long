/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:58:57 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/09 15:49:53 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/headers/time_manager.h"
#include "../libft/headers/libft.h"
#include "../headers/so_long.h"

typedef	struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_draw_square(t_data *data, int x, int y,int size, int color)
{
	int		i;
	int		j;

	i = x -1;
	j = y -1;
	while (++i < x + size)
		my_mlx_pixel_put(data, i, j, color);
	while (++j < y + size)
		my_mlx_pixel_put(data, i, j, color);
	while (--i > x)
		my_mlx_pixel_put(data, i, j, color);
	while (--j > y)
		my_mlx_pixel_put(data, i, j, color);
}

int main(void)
{
	void *mlx_ptr;
	void *mlx_win_ptr;
	t_data	data;

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
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_put_image_to_window(mlx_ptr, mlx_win_ptr, data.img, 0, 0);
	my_mlx_draw_square(&data, 10, 10, 100, 0x00FF0000);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr,mlx_win_ptr);
	mlx_destroy_image(mlx_ptr, data.img);
	free(mlx_ptr);
	return (0);
}
