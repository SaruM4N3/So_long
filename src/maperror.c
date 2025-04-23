/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maperror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:04:37 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/23 12:10:12 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/map.h"
#include "../headers/error.h"

static void     check_for_player_and_exit(t_gameenv *env)
{
    int exitcount;
    int playercount;
    int y;
    int x;

    y = -1;
    x = -1;
    exitcount = 0;
    playercount = 0;
    while (env->map.grid[++y])
    {
        while (env->map.grid[y][++x])
        {
            if (env->map.grid[y][x] == 'P')
                playercount++;
            if (env->map.grid[y][x] == 'E')
                exitcount++;
        }
        x = 0;
    }
    if (playercount != 1)
        print_custom_error("Loading map", ERRMAPPLAYER);
    if (exitcount != 1)
		print_custom_error("Loading map", ERRMAPEXIT);
}

int 	map_parsing_check(t_gameenv *env)
{
	if (!ft_strnstr(env->map.path,".ber",ft_strlen(env->map.path)))
    {
		print_custom_error("Loading map", ERRNOMAP);
        return (0);
    }
    check_for_player_and_exit(env);
    return (1);
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

