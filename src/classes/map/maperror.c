/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maperror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:37 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/14 02:31:00 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/classes/map.h"
# include "headers/error.h"

void	map_doesnt_exist(t_map *map)
{
	if (!map)
		print_custom_error("Loading map", ERRNOMAP);	
}

void free_2d_array(char **array, int height)
{
    int	i;

    i = 0;
    while (i < height)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

