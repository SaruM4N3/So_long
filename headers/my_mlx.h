/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:26:09 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/16 23:27:26 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

typedef struct s_coord
{
	int		pos_x;
	int		pos_y;
	int		target_x;
	int		target_y;
}			t_coord;

enum colors 
{
	red = 0x00FF0000,
	green = 0x0000FF00,
	blue = 0x000000FF,
	cyan = 0x0000FFFF,
	yellow = 0x00FFFF00,
	magenta = 0x00FF00FF,
	orange = 0x00FF8000,
	grey = 0x00888888,
	white = 0xFFFFFFFF
};

//Draw
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	my_mlx_draw_line(t_img *data, t_coord *coord, int color);
void	my_mlx_draw_square(t_img *data, t_coord *coord, int size, int color);
void	my_mlx_draw_tester(t_img data);
