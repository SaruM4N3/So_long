/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:36:10 by sarunomane        #+#    #+#             */
/*   Updated: 2025/04/09 15:23:01 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/headers/time_manager.h" 
# include "../libft/headers/libft.h" 
# include "../headers/so_long.h" 
# include "stdio.h" 

int	update(t_time *time)
{
	time->uptime = get_proc_uptime();
	time->deltatime = get_deltatime();
	time->framerate = get_frames_per_second();
	printf("Uptime: %f (in second);\tDeltatime: %f;\tFramerate: %f;", time->uptime, time->deltatime, time->framerate);
	return (0);
}