/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:48:14 by mbourdel          #+#    #+#             */
/*   Updated: 2015/04/10 15:18:31 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			color1(t_pt2d point, t_env *env, unsigned int *color)
{
	if (point.memz > (env->value.alt_max * 0.8))
		*color = 0xFFFFFF;
	else if (point.memz > (env->value.alt_max * 0.55)
				&& (point.memz <= (env->value.alt_max * 0.8)))
		*color = 0x663300;
	return ;
}

static void			color2(t_pt2d point, t_env *env, unsigned int *color)
{
	if (point.memz < (env->value.alt_max * 0.55))
		*color = 0x996633;
	if (point.memz < (env->value.alt_max * 0.40))
		*color = 0xD1A319;
	if (point.memz < (env->value.alt_max * 0.30))
		*color = 0x669900;
	if (point.memz < (env->value.alt_max * 0.20))
		*color = 0x009900;
	if (point.memz < (env->value.alt_max * 0.15))
		*color = 0x009933;
	if (point.memz < (env->value.alt_max * 0.10))
		*color = 0x006600;
	if (point.memz < (env->value.alt_max * 0.05))
		*color = 0x005200;
	if (point.memz < (env->value.alt_max * 0.02))
		*color = 0x194D19;
	return ;
}

static void			color3(t_pt2d point, t_env *env, unsigned int *color)
{
	if (point.memz < 0)
	{
		*color = 0x0099FF;
		if (point.memz < (env->value.alt_min * 0.7))
			*color = 0x0000FF;
	}
	return ;
}

unsigned int		ft_color(t_pt2d point, t_env *env)
{
	unsigned int		color;

	color = 0xFFFFFF;
	if (env->value.color != 0)
	{
		color1(point, env, &color);
		color2(point, env, &color);
		color3(point, env, &color);
	}
	return (color);
}
