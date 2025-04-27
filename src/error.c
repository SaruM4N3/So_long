/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:06:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/27 14:04:07 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include <errno.h>
#include <string.h>

static char	*str_custom_errors2( int err)
{
	if (err == ERRNOVALIDPATH)
		return ("Invalid path between player, coins and exit");
	if (err == ERRMAPSIZE)
		return ("Invalid map size");
	if (err == ERRTEXTURE)
		return ("Texture load failed");
	return (NULL);
}

static char	*str_custom_errors(char *category, int err)
{
	(void)category;
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
	if (err == ERRMAPCOIN)
		return ("Coin count < 1");
	if (err == ERRMAPWALL)
		return ("Map isn't closed by walls");
	if (err == ERRMAPPATH)
		return ("Map path doesnt contain .ber");
	if (str_custom_errors2(err))
		return (str_custom_errors2(err));
	return ("Unknown error !");
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

int	free_2d(char **tab, int return_value)
{
	int	y;

	y = 0;
	while (tab[y])
		free(tab[y++]);
	free(tab);
	return (return_value);
}
