/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 10:44:24 by mbourdel          #+#    #+#             */
/*   Updated: 2015/04/28 12:28:19 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_destroy_map(t_env *env)
{
	t_map	tmp;

	if (!env->map)
		return ;
	while (env->map)
	{
		tmp = env->map->nxt;
		free(env->map->intline);
		free(env->map);
		env->map = tmp;
	}
	env->map = NULL;
	return ;
}

static void		ft_key_effect2(int keycode, t_env *env)
{
	if (keycode == ENTER)
		env->value.setup == 0 ? (env->value.setup = 1)
			: (env->value.setup = 0);
	else if (keycode == KK)
		env->value.color == 0 ? (env->value.color = 1)
			: (env->value.color = 0);
	else if (keycode == 18 && env->value.proj != 0)
		env->value.proj = 0;
	else if (keycode == 19 && env->value.proj != 1)
		env->value.proj = 1;
	else if (keycode == 20 && env->value.proj != 2)
		env->value.proj = 2;
	return ;
}

static void		ft_key_effect(int keycode, t_env *env)
{
	if (keycode == RIGHT)
		env->value.xvar += 30;
	else if (keycode == LEFT)
		env->value.xvar -= 30;
	else if (keycode == UP)
		env->value.yvar -= 20;
	else if (keycode == DOWN)
		env->value.yvar += 20;
	else if (keycode == PLUS)
		env->value.height *= 1.1;
	else if (keycode == MOIN)
		env->value.height *= 0.9;
	else if (keycode == CRO_OP && env->value.space >= 1)
	{
		env->value.space *= 0.9;
		if (fabs(env->value.height) > 1.1)
			env->value.height *= 0.9;
	}
	else if (keycode == CRO_OF && env->value.space <= 300)
	{
		env->value.space *= 1.1;
		env->value.height *= 1.1;
	}
	ft_key_effect2(keycode, env);
	return ;
}

int				key_hook(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		ft_destroy_map(env);
		exit(0);
	}
	ft_key_effect(keycode, env);
	ft_map(env);
	ft_bzero(env->img.data,
			(YWIN_SIZE * env->img.sizeline + XWIN_SIZE * (env->img.bpp / 8)));
	ft_draw_pt2d(env);
	ft_print_hud(env);
	return (0);
}

int				expose_hook(t_env *env)
{
	ft_bzero(env->img.data, (XWIN_SIZE * YWIN_SIZE * (env->img.bpp / 8)));
	ft_draw_pt2d(env);
	ft_print_hud(env);
	return (0);
}
