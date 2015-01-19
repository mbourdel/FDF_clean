/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 14:03:58 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/19 15:53:05 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_change_proj(t_env *env)
{
	t_ls3d		pt3d;

	if (env->value.proj == 0)
	{
		env->value.xbegin = XBEGIN;
		env->value.ybegin = YBEGIN;
		pt3d = ft_set_pt3d(env->map, env);
		env->pt2d = ft_set_pt2d(pt3d, env);
	}
	if (env->value.proj == 1)
	{
		env->value.xbegin = 100;
		env->value.ybegin = 100;
		pt3d = ft_set2_pt3d(env->map, env);
		env->pt2d = ft_set2_pt2d(pt3d, env);
	}
	if (env->value.proj == 2)
	{
		env->value.xbegin = XBEGIN + 300;
		env->value.ybegin = YBEGIN;
		pt3d = ft_set2_pt3d(env->map, env);
		env->pt2d = ft_set3_pt2d(pt3d, env);
	}
	return ;
}

int				ft_map(t_env *env)
{
	static int	i = 0;

	if (i == 0)
	{
		i = 1;
		env->map = NULL;
		env->map = ft_get_the_map(env->fd, env->map);
		if (env->map == NULL)
			return (1);
	}
	ft_change_proj(env);
	return (0);
}
