/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:06:42 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/17 01:22:23 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include <errno.h>
#include <string.h>

static char	*str_custom_errors(char *category, int err)
{
	if (ft_strncmp(category, "Loading Map", 50) == 0)
	{
		if (err == ERRNOMAP)
			return ("Map doesnt exist");
		if (err == ERRMAPISNOTRECT)
			return ("Map is not rectangular");
		if (err == ERRMAPCHAR)
			return ("Invalid characters're contained in map");
		if (err == ERRMAPPLAYER)
			return ("Player doesnt not exist or more than one");
		if (err == ERRMAPEXIT)
			return ("Exit doesnt not exist or more than one");
		if (err == ERRMAPWALL)
			return ("Not closed by walls");
		if (err == ERRMAPPATH)
			return ("No path availabe");
	}
	return ("Unknown error");
}

int	print_custom_error(char *category, int err)
{
	if (!err || !category)
		return (-1);
	ft_printf("Custom Error: %s", str_custom_errors(category, err));
	return (0);
}
