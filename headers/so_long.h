/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:01:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/18 15:45:54 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include "../libft/headers/libft.h"
# include "../libft/headers/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

// Struct

typedef struct s_2Dvector
{
	int			x;
	int			y;
}				t_2Dvector;

typedef struct s_player
{
	t_2Dvector	pos;
}				t_player;

typedef struct s_map
{
	char		**grid;
	char		*path;
	int			width;
	int			height;
	t_2Dvector	player_pos;
}				t_map;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_gameenv
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_player	player;
	t_map		map;
}				t_gameenv;

// Game
void			close_env(t_gameenv *env);

// Event
int				handle_input(int key, t_gameenv *env);
int				handle_no_event(void);

// Player
t_player		init_player(int x, int y, t_gameenv *env);
void			set_player_pos(t_player *player, int x, int y);

// Move
int				move_up(t_player player, t_map map);
int				move_left(t_player player, t_map map);
int				move_down(t_player player, t_map map);
int				move_right(t_player player, t_map map);

#endif