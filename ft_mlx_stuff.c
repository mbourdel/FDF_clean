/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 10:44:24 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/23 17:34:19 by mbourdel         ###   ########.fr       */
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
	if (keycode == 65293)
		env->value.setup == 0 ? (env->value.setup = 1)
			: (env->value.setup = 0);
	if (keycode == 107)
		env->value.color == 0 ? (env->value.color = 1)
			: (env->value.color = 0);
	if (keycode == 49 && env->value.proj != 0)
		env->value.proj = 0;
	if (keycode == 50 && env->value.proj != 1)
		env->value.proj = 1;
	if (keycode == 51 && env->value.proj != 2)
		env->value.proj = 2;
	return ;
}

static void		ft_key_effect(int keycode, t_env *env)
{
	if (keycode == 65363)
		env->value.xvar += 30;
	if (keycode == 65361)
		env->value.xvar -= 30;
	if (keycode == 65362)
		env->value.yvar -= 20;
	if (keycode == 65364)
		env->value.yvar += 20;
	if (keycode == 65451)
		env->value.height *= 1.1;
	if (keycode == 65453)
		env->value.height *= 0.9;
	if (keycode == 91 && env->value.space >= 1)
	{
		env->value.space *= 0.9;
		if (abs(env->value.height) > 1.1)
			env->value.height *= 0.9;
	}
	if (keycode == 93 && env->value.space <= 300)
	{
		env->value.space *= 1.1;
		env->value.height *= 1.1;
	}
	ft_key_effect2(keycode, env);
	return ;
}

int				key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
	{
		ft_destroy_map(env);
		exit(0);
	}
	ft_key_effect(keycode, env);
	ft_map(env);
	ft_bzero(env->img.data, (XWIN_SIZE * YWIN_SIZE * (env->img.bpp / 8)));
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
