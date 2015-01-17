/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_the_taff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:03:51 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/17 12:59:33 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_pt2d(t_env *env)
{
	int		i;

	i = 0;
	while (env->pt2d[i].x != 0)
	{
		if (i > 0 && env->pt2d[i].line == env->pt2d[i - 1].line)
			ft_draw(env->pt2d[i - 1], env->pt2d[i], env);
		if (env->pt2d[i].stay_high != NULL)
			ft_draw(env->pt2d[i], env->pt2d[i].stay_high[0], env);
		i++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img_ptr, 0, 0);
	return ;
}
