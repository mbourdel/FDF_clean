/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set2_pt3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 19:07:09 by mbourdel          #+#    #+#             */
/*   Updated: 2015/04/09 01:26:19 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_nb_point(t_map map)
{
	int		nb;

	nb = 0;
	while (map != NULL)
	{
		nb += (map->size + 1);
		map = map->nxt;
	}
	return (nb);
}

static t_ls3d	ft_stay_high(t_ls3d point, int *i, int size)
{
	if (i[2] > 0)
		return (&point[i[1] - size]);
	return (NULL);
}

t_ls3d			ft_set2_pt3d(t_map map, t_env *env)
{
	float		xyz[2];
	t_ls3d		point;
	int			i[3];

	i[1] = 0;
	i[2] = 0;
	point = (t_ls3d)malloc(sizeof(t_pt3d) * (ft_nb_point(map) + 1));
	xyz[1] = env->value.ybegin;
	while (map != NULL && ((xyz[0] = env->value.xbegin) || 1))
	{
		i[0] = 0;
		while (i[0] < map->size)
		{
			point[i[1]].x = xyz[0] + (env->value.space * i[0]);
			point[i[1]].y = xyz[1];
			point[i[1]].stay_high = ft_stay_high(point, i, map->size);
			point[i[1]].line = i[2];
			point[i[1]++].z = map->intline[i[0]++];
		}
		xyz[1] += env->value.space;
		map = map->nxt;
		i[2] += 1;
	}
	point[i[1]].x = 0;
	return (point);
}
