/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:35:29 by mbourdel          #+#    #+#             */
/*   Updated: 2015/04/08 22:58:43 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_pixel_put_img(t_env *env, int x, int y, unsigned int color)
{
	int				i;
	unsigned char	clr[(env->img.bpp / 8) - 1];

	if (!(x >= XWIN_SIZE || y >= YWIN_SIZE) && x >= 0 && y >= 0)
	{
		i = 0;
		while (i < (env->img.bpp / 8) - 1)
		{
			clr[i] = color >> ((i * 8));
			i++;
		}
		while (i >= 0)
		{
			env->img.data[y * env->img.sizeline +
				(x * (env->img.bpp / 8) + i)] = clr[i];
			i--;
		}
	}
	return ;
}
