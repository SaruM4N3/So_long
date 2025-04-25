/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:06:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/25 15:16:51 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include <errno.h>
#include <string.h>

static char	*str_custom_errors(char *category, int err)
{
	if (ft_strncmp(category, "Loading map", 12) == 0)
	{
		if (err == ERRNOMAP)
			return ("No map found\nPlease proceed as follow\n\
<<./so_long 'path_to_map.ber'>>");
		if (err == ERRMAPISNOTRECT)
			return ("Map is not rectangular");
		if (err == ERRMAPCHAR)
			return ("Invalid characters're contained in the map");
		if (err == ERRMAPPLAYER)
			return ("Player count != 1");
		if (err == ERRMAPEXIT)
			return ("Exit count != 1");
		if (err == ERRMAPWALL)
			return ("Map's closed by walls");
		if (err == ERRMAPPATH)
			return ("Map path doesnt contain .ber");
	}
	return ("Unknown error\n");
}

int	print_custom_error(char *category, int err)
{
	if (!err || !category)
		return (-1);
	ft_printf("Custom Error: %s\n", str_custom_errors(category, err));
	return (0);
}

int	print_error_and_return(int err)
{
	print_custom_error("Loading map", err);
	return (0);
}
