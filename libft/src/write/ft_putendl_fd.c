/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:06:53 by zsonie            #+#    #+#             */
/*   Updated: 2025/02/14 21:58:51 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;

	if (!s || fd <= 0)
		return ;
	i = 0;
	while (s[i])
	{
		if (write (fd, &s[i], 1) < 0)
			return ;
		i++;
	}
	ft_putchar_fd('\n', fd);
}
