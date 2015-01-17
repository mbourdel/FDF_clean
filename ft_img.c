/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:14:55 by mbourdel          #+#    #+#             */
/*   Updated: 2014/12/27 18:43:42 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_img(t_env *env)
{
	env->img.img_ptr = mlx_new_image(env->mlx, XWIN_SIZE, YWIN_SIZE);
	env->img.data = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp,
			&env->img.sizeline, &env->img.endian);
	return ;
}
