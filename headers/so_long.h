/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:01:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/17 01:29:57 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include "../libft/headers/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

// Struct

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
}			t_player;

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

// Game
void		close_env(t_gameenv *env);

// Event
int			handle_input(int key, t_gameenv *env);
int			handle_no_event(void);

// Player
t_player	init_player(int x, int y);
void		set_player_pos(t_player *player, int x, int y);

// Move
int			move_up(void);
int			move_left(void);
int			move_down(void);
int			move_right(void);

#endif