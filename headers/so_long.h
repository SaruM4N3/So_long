/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:01:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/26 02:42:28 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include "../libft/headers/ft_printf.h"
# include "../libft/headers/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>

// Struct

typedef struct s_2dvector
{
	int			x;
	int			y;
}				t_2dvector;

typedef struct s_player
{
	t_2dvector	pos;
	int			coins;
}				t_player;

typedef struct s_map
{
	char		**grid;
	char		*path;
	int			width;
	int			height;
	int			coins_nb;
	t_2dvector	player_pos;
	t_2dvector	exit_pos;
}				t_map;

typedef struct s_img
{
	void		*img;
	void		*img_ground;
	void		*img_wall;
	void		*img_collect;
	void		*img_player;
	void		*img_player_exit;
	void		*img_exit;
	char		*addr;
	char		*ground_path;
	char		*wall_path;
	char		*coin_path;
	char		*player_path;
	char		*player_exit_path;
	char		*exit_path;
	int			line_length;
	int			bits_per_pixel;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_gameenv
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_img		img;
	t_player	player;
	t_map		map;
}				t_gameenv;

// Game
/**
 * @brief Frees all resources and closes the game environment.
 * 
 * This function is responsible for releasing any allocated memory,
 * closing any open files or connections, and performing any necessary
 * cleanup to properly terminate the game environment.
 * 
 * @param env A pointer to the game environment structure to be closed.
 */
void			close_env(t_gameenv *env);

// Event
/**
 * @brief Handles keyboard input for the game environment.
 * 
 * @param key The keycode of the pressed key.
 * @param env A pointer to the game environment structure.
 * @return An integer indicating the result of the input handling.
 *         Typically, this could be used to signal success, failure,
 *         or a specific action to be taken.
 */
int				handle_input(int key, t_gameenv *env);
/**
 * @brief Handles the case where no event occurs in the game environment.
 * 
 * This function is called when there are no events to process. It can be used
 * to perform any necessary updates or checks in the game environment during
 * idle periods.
 * 
 * @param env A pointer to the game environment structure.
 * 
 * @return An integer value indicating the result of the operation. The specific
 *         return values should be defined based on
 * 	       the application's requirements.
 */
int				handle_no_event(t_gameenv *env);

// Player
/**
 * @brief Initializes a player structure
 *  with the given position and game environment.
 * 
 * @param x The x-coordinate of the player's initial position.
 * @param y The y-coordinate of the player's initial position.
 * @param env Pointer to the game environment structure.
 * @return A t_player structure initialized
 *  with the specified position and environment.
 */
t_player		init_player(int x, int y, t_gameenv *env);
/**
 * @brief Sets the position of the player on the game map.
 * 
 * This function updates the player's position by assigning the
 * specified x and y coordinates to the player's structure.
 * 
 * @param player A pointer to the t_player structure representing the player.
 * @param x The x-coordinate to set the player's position.
 * @param y The y-coordinate to set the player's position.
 */
void			set_player_pos(t_player *player, int x, int y);

// Move
int				move_up(t_player *player, t_map map);
int				move_left(t_player *player, t_map map);
int				move_down(t_player *player, t_map map);
int				move_right(t_player *player, t_map map);

// Render & RenderUtils
/**
 * @brief Initializes images from XPM files for the game environment.
 * 
 * @param env Pointer to the game environment structure.
 * @return int Returns 0 on success, or a non-zero value on failure.
 */
int				init_img_from_xpm(t_gameenv *env);

/**
 * @brief Initializes player-specific images from XPM files.
 * 
 * @param env Pointer to the game environment structure.
 * @return int Returns 0 on success, or a non-zero value on failure.
 */
int				init_player_img_from_xpm(t_gameenv *env);

/**
 * @brief Cleans up and releases resources used for rendering.
 * 
 * @param env Pointer to the game environment structure.
 * @return int Returns 0 on success, or a non-zero value on failure.
 */
int				clean_render(t_gameenv *env);

/**
 * @brief Renders all images in the game environment.
 * 
 * @param env Pointer to the game environment structure.
 * @return int Returns 0 on success, or a non-zero value on failure.
 */
int				render_img(t_gameenv *env);

/**
 * @brief Renders the player image at the specified coordinates.
 * 
 * @param env Pointer to the game environment structure.
 * @param x X-coordinate where the player image will be rendered.
 * @param y Y-coordinate where the player image will be rendered.
 */
void			render_player_img(t_gameenv *env, int x, int y);

/**
 * @brief Renders other images (non-player) at the specified coordinates.
 * 
 * @param env Pointer to the game environment structure.
 * @param x X-coordinate where the image will be rendered.
 * @param y Y-coordinate where the image will be rendered.
 */
void			render_other_img(t_gameenv *env, int x, int y);

int				free_2d(char **tab, int return_value);

#endif