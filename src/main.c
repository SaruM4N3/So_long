/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:58:57 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/13 16:56:02 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../libft/headers/libft.h"
#include "../libft/headers/time_manager.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_coord
{
	int		pos_x;
	int		pos_y;
	int		target_x;
	int		target_y;
}			t_coord;

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
	*(unsigned int *)dst = color;
}

// void	my_mlx_draw_line(t_data *data, t_coord *coord, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (i < coord->target_x - coord->pos_x  || j < coord->target_y - coord->pos_y )
// 	{
// 		if (i < coord->target_x - coord->pos_x)
// 			i++;
// 		if (j < coord->target_y - coord->pos_y)
// 			j++;
// 		my_mlx_pixel_put(data, i + coord->pos_x, j + coord->pos_y, color);
// 	}
// }

void	my_mlx_draw_line(t_data *data, t_coord *coord, int color)
{
    float	x;
    float	y;
    float	x_inc;
    float	y_inc;
    int		steps;

    // Determine the number of steps based on the larger magnitude of dx or dy
    if ((coord->target_x - coord->pos_x) > (coord->target_y - coord->pos_y))
        steps = (coord->target_x - coord->pos_x);
    else
        steps = (coord->target_y - coord->pos_y);

    x_inc = (coord->target_x - coord->pos_x) / (float)steps;
    y_inc = (coord->target_y - coord->pos_y) / (float)steps;
    x = coord->pos_x;
    y = coord->pos_y;
    while (steps-- >= 0)
    {
        my_mlx_pixel_put(data, (int)x, (int)y, color);
        x += x_inc;
        y += y_inc;
    }
}

void	my_mlx_draw_square(t_data *data, t_coord *coord, int size, int color)
{
	int	i;
	int	j;

	i = coord->pos_x - 1;
	j = coord->pos_y - 1;
	while (++i < coord->pos_x + size)
		my_mlx_pixel_put(data, i, j, color);
	while (++j < coord->pos_y + size)
		my_mlx_pixel_put(data, i, j, color);
	while (--i > coord->pos_x)
		my_mlx_pixel_put(data, i, j, color);
	while (--j > coord->pos_y)
		my_mlx_pixel_put(data, i, j, color);
}

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
	my_mlx_draw_square(&data, &coord, 100, 0x00FF0000);
	my_mlx_draw_line(&data, &coord, 0x00FF0000);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, mlx_win_ptr);
	mlx_destroy_image(mlx_ptr, data.img);
	free(mlx_ptr);
	return (0);
}
