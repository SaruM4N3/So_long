/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:46:44 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/14 00:50:27 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/my_mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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
