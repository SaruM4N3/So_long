/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:01:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/17 01:29:38 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// Includes
# include "../libft/headers/ft_printf.h"
# include "../libft/headers/libft.h"
# include "./map.h"
# include "./so_long.h"

// Defines
# define MAPERR_CATEGORY "Loading map"
# define MAPERROR 1000
# define ERRNOMAP MAPERROR + 1
# define ERRMAPISNOTRECT MAPERROR + 2
# define ERRMAPCHAR MAPERROR + 3
# define ERRMAPPLAYER MAPERROR + 4
# define ERRMAPEXIT MAPERROR + 5
# define ERRMAPWALL MAPERROR + 6
# define ERRMAPPATH MAPERROR + 7

# define TEXTERR_CATEGORY "Loading texture"
# define TEXTERROR 2000
# define ERRTEXARGS TEXTERROR + 1
# define ERRTEXNOFS TEXTERROR + 2

// Functions
/**
 * @brief print a custom error message to figure out what's happening

	* @param category: the category of the error ("Loading map" or "Loading texture")
 * @param error: the error code
 * @return: nothing
 */
int		print_custom_error(char *category, int error);

void	map_doesnt_exist(t_map *map);

#endif