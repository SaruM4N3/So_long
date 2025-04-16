/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 23:24:11 by zsonie            #+#    #+#             */
/*   Updated: 2025/04/16 23:57:10 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"


static int	move_count(void)
{
	static int count = 0;

	count++;
	__builtin_printf("MoveCount : %d\n",count);
	return (count);
}

int	move_up(void)
{
	__builtin_printf("%s", "Move Up\n");
	move_count();
	return (0);
}

int	move_left(void)
{
	__builtin_printf("%s", "Move Left\n");
	move_count();
	return (0);
}

int	move_down(void)
{
	__builtin_printf("%s", "Move Down\n");
	move_count();
	return (0);
}

int	move_right(void)
{
	__builtin_printf("%s", "Move Right\n");
	move_count();
	return (0);
}
