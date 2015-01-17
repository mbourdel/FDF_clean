/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:48:14 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/15 19:09:11 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int		ft_color(t_pt2d point, t_env *env)
{
	unsigned int		color;

	color = 0xFFFFFF;
	if (point.memz != 0)
	{
		if (point.memz == env->value.alt_max)
			color = 0xFF0000;
		if (point.memz == env->value.alt_min)
			color = 0x0000FF;
	}
	return (color);
}
