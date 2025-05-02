/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:46:44 by zsonie            #+#    #+#             */
/*   Updated: 2025/05/02 14:06:51 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/my_mlx.h"
#include "../../headers/so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_draw_line(t_img *data, t_coord *coord, int color)
{
	float	x;
	float	y;
	float	x_inc;
	float	y_inc;
	int		steps;

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

void	my_mlx_draw_square(t_img *data, t_coord *coord, int size, int color)
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

void	my_mlx_draw_tester(t_img data)
{
	t_coord	coord;

	coord.pos_x = 100;
	coord.pos_y = 100;
	coord.target_x = 300;
	coord.target_y = 600;
	my_mlx_draw_square(&data, &coord, 10, red);
	my_mlx_draw_square(&data, &coord, 20, green);
	my_mlx_draw_square(&data, &coord, 30, blue);
	my_mlx_draw_square(&data, &coord, 40, cyan);
	my_mlx_draw_square(&data, &coord, 50, yellow);
	my_mlx_draw_square(&data, &coord, 60, orange);
	my_mlx_draw_square(&data, &coord, 70, grey);
	my_mlx_draw_square(&data, &coord, 80, white);
	my_mlx_draw_line(&data, &coord, cyan);
}
