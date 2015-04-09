/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:13:23 by mbourdel          #+#    #+#             */
/*   Updated: 2015/04/09 04:44:10 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_cone(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	origin.memz >= arrival.memz ? (color = ft_color(origin, env))
		: (color = ft_color(arrival, env));
	e = arrival.x - origin.x;
	dx = e * 2;
	dy = abs(arrival.y - origin.y) * 2;
	while (origin.x <= arrival.x)
	{
		ft_pixel_put_img(env, (origin.x + env->value.xvar),
				(origin.y + env->value.yvar), color);
		origin.x += 1;
		if ((e -= dy) <= 0)
		{
			origin.y -= 1;
			e += dx;
		}
	}
	return ;
}

void		ft_draw_ctwo(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	origin.memz >= arrival.memz ? (color = ft_color(origin, env))
		: (color = ft_color(arrival, env));
	e = arrival.x - origin.x;
	dx = e * 2;
	dy = abs(arrival.y - origin.y) * 2;
	while (origin.x <= arrival.x)
	{
		ft_pixel_put_img(env, (origin.x + env->value.xvar),
				(origin.y + env->value.yvar), color);
		origin.x += 1;
		if ((e -= dy) <= 0)
		{
			origin.y += 1;
			e += dx;
		}
	}
	return ;
}

void		ft_draw_cfive(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	origin.memz >= arrival.memz ? (color = ft_color(origin, env))
		: (color = ft_color(arrival, env));
	e = arrival.y - origin.y;
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->value.xvar),
				(origin.y + env->value.yvar), color);
		origin.y += 1;
		if ((e -= dx) <= 0)
		{
			origin.x -= 1;
			e += dy;
		}
	}
	return ;
}

void		ft_draw_csix(t_pt2d origin, t_pt2d arrival, t_env *env)
{
	int				dx;
	int				dy;
	int				e;
	unsigned int	color;

	origin.memz >= arrival.memz ? (color = ft_color(origin, env))
		: (color = ft_color(arrival, env));
	e = arrival.y - origin.y;
	dy = e * 2;
	dx = abs(arrival.x - origin.x) * 2;
	while (origin.y <= arrival.y)
	{
		ft_pixel_put_img(env, (origin.x + env->value.xvar),
				(origin.y + env->value.yvar), color);
		origin.y += 1;
		if ((e -= dx) <= 0)
		{
			origin.x += 1;
			e += dy;
		}
	}
	return ;
}
