/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:01:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/16 23:30:04 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/headers/libft.h"
# include "../minilibx-linux/mlx.h"

// Struct
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_gameenv
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}			t_gameenv;

// typedef struct s_time
// {
// 	double	uptime;
// 	double	deltatime;
// 	double	framerate;
// }			t_time;

// Game
void		close_env(t_gameenv *env);

// Event
int			handle_input(int key, t_gameenv *env);
int			handle_no_event(void);

// Move
int			move_up();
int			move_left();
int			move_down();
int			move_right();

#endif