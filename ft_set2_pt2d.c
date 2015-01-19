/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set2_pt2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 19:08:54 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/19 13:24:19 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_nb_point(t_ls3d pt3d)
{
	int			nb;

	nb = 0;
	while (pt3d[nb].x)
		nb++;
	return (nb);
}

static t_ls2d	ft_stay_high(int i, t_ls3d pt3d, t_env *env)
{
	t_ls2d		stay_high;

	if (pt3d[i].stay_high == NULL)
		return (NULL);
	stay_high = (t_ls2d)malloc(sizeof(t_pt2d));
	stay_high->x = (((pt3d[i].stay_high->x
					+ (env->value.cst * pt3d[i].stay_high->z))));
	stay_high->y = ((pt3d[i].stay_high->y)
					+ ((env->value.cst / 2)
					* -pt3d[i].stay_high->z * env->value.height));
	stay_high->memz = pt3d[i].stay_high->z;
	return (stay_high);
}

t_ls2d			ft_set2_pt2d(t_ls3d pt3d, t_env *env)
{
	t_ls2d		point;
	int			i;

	i = 0;
	point = (t_ls2d)malloc(sizeof(t_pt2d) * (ft_nb_point(pt3d) + 1));
	while ((int)pt3d[i].x)
	{
		point[i].x = (((pt3d[i].x + (env->value.cst * pt3d[i].z))));
		point[i].y = ((pt3d[i].y)
					+ ((env->value.cst / 2) * -pt3d[i].z * env->value.height));
		point[i].memz = pt3d[i].z;
		point[i].stay_high = ft_stay_high(i, pt3d, env);
		point[i].line = pt3d[i].line;
		i++;
	}
	return (point);
}
