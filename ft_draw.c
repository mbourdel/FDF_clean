/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 13:24:57 by mbourdel          #+#    #+#             */
/*   Updated: 2015/04/28 15:40:18 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	float		dx;
	float		dy;

	dx = arrival.x - origin.x;
	dy = arrival.y - origin.y;
	if (fabs(dx) > fabs(dy))
	{
		if (dx > 0)
			dy <= 0 ? ft_draw_cone(origin, arrival, env)
				: ft_draw_ctwo(origin, arrival, env);
		else
			dy >= 0 ? ft_draw_cone(arrival, origin, env)
				: ft_draw_ctwo(arrival, origin, env);
	}
	else
	{
		if (dy < 0)
			dx >= 0 ? ft_draw_cfive(arrival, origin, env)
				: ft_draw_csix(arrival, origin, env);
		else
			dx <= 0 ? ft_draw_cfive(origin, arrival, env)
				: ft_draw_csix(origin, arrival, env);
	}
	return ;
}
