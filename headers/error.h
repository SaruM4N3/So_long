/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:01:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/29 15:19:41 by zsonie           ###   ########.fr       */
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
# define ERRNOMAP 1001
# define ERRMAPISNOTRECT 1002
# define ERRMAPCHAR 1003
# define ERRMAPPLAYER 1004
# define ERRMAPEXIT 1005
# define ERRMAPWALL 1006
# define ERRMAPPATH 1007
# define ERRNOVALIDMAPPATH 1008
# define ERRNOVALIDPATH 1009
# define ERRMAPCOIN 1010
# define ERRMAPSIZE 1011
# define ERRTEXTURE 1012

// Functions

/**
 * @brief Handles the case where the specified map does not exist.
 *
 * This function is called when the provided map pointer is invalid or
 * the map cannot be found. It is responsible for managing the error
 * condition appropriately.
 *
 * @param map A pointer to the map structure that is being checked.
 *            If the map does not exist, this function will handle
 *            the error.
 */
int	map_parsing_check(t_gameenv *env);

/**
 * @brief print a custom error message to figure out what's happening

	* @param category: the category of the error
	("Loading map" or "Loading texture")
 * @param error: the error code
 * @return: 0
 */
int	print_custom_error(char *category, int error);

/**
 * @brief Prints an error message corresponding 
 * to the given error code and returns 0.
 *
 * @param err The error code to be printed and returned.
 * @return 0.
 */
int	print_error_and_return(int err);

#endif