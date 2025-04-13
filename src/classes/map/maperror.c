/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maperror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:37 by sarunomane        #+#    #+#             */
/*   Updated: 2025/02/22 17:03:31 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/classes/map.h"
# include "headers/error.h"

void	map_doesnt_exist(t_map *map)
{
	if (!map)
		print_custom_error("Loading map", ERRNOMAP);	
}

