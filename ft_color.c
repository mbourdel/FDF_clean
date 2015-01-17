/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:48:14 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/17 16:25:44 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int		ft_color(t_pt2d point, t_env *env)
{
	unsigned int		color;

	color = 0xFFFFFF;
	if (env->value.color != 0)
	{
		if (point.memz == env->value.alt_max)
			color = 0x996633;
		else if (point.memz > (env->value.alt_max * 0.8) && point.memz < env->value.alt_max)
			color = 0x996633;
		else if (point.memz > (env->value.alt_max * 0.65) && (point.memz <= (env->value.alt_max * 0.8)))
			color = 0xD1A319;
		else if (point.memz < 0)
		{
			color = 0x0099FF;
			if (point.memz < (env->value.alt_min * 0.8) && point.memz > env->value.alt_min)
				color = 0x0000FF;
		}
		else
			color = 0x009900;

	}
	return (color);
}
