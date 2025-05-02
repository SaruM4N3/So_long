/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:58:29 by zsonie            #+#    #+#             */
/*   Updated: 2025/05/02 14:00:18 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"
#include <limits.h>
#include <math.h>

double	ft_atof(const char *str)
{
	int			i;
	double		num;
	int			precision_factor;
	const char	*precision_part;

	i = -1;
	num = 0;
	precision_factor = 0;
	precision_part = str;
	num = ft_atoi(str);
	while (str[++i] && ft_isdigit(str[i]))
		precision_part++;
	if (*precision_part == '.' || *precision_part == ',')
		precision_part++;
	i = -1;
	while (precision_part[++i] && ft_isdigit(precision_part[i]))
		precision_factor++;
	precision_factor = pow(10, precision_factor);
	num = num + (double)ft_atoi(precision_part) / (double)precision_factor;
	return (num);
}
