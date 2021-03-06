/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_altitude.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:45:53 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/19 15:36:06 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_altitude(t_env *env)
{
	int			i;

	env->value.alt_max = env->pt2d[0].memz;
	env->value.alt_min = env->pt2d[0].memz;
	i = 0;
	while (env->pt2d[i].x != 0)
	{
		if (env->pt2d[i].memz > env->value.alt_max)
			env->value.alt_max = env->pt2d[i].memz;
		if (env->pt2d[i].memz < env->value.alt_min)
			env->value.alt_min = env->pt2d[i].memz;
		i++;
	}
	return ;
}
