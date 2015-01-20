/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:41:16 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/20 16:23:33 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_print_hud(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 20, 20, WHITE,
		"Press \"ENTER\" to switch on/off the HUD");
	if (env->value.setup == 1)
	{
		mlx_string_put(env->mlx, env->win, 20, 40, WHITE,
			ft_strjoin("ALT MAX : ", ft_itoa(env->value.alt_max)));
		mlx_string_put(env->mlx, env->win, 20, 60, WHITE,
			ft_strjoin("ALT MIN : ", ft_itoa(env->value.alt_min)));
		mlx_string_put(env->mlx, env->win, 20, 80, WHITE,
			ft_strjoin("ZOOM : ", ft_ftoa(env->value.space)));
		mlx_string_put(env->mlx, env->win, 20, 100, WHITE,
			ft_strjoin("HEIGHT : ", ft_ftoa(env->value.height)));
		mlx_string_put(env->mlx, env->win, 20, 120, WHITE,
			ft_strjoin("CONSTANT : ", ft_ftoa(env->value.cst)));
	}
	return ;
}
