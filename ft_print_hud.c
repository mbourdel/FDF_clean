/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hud.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:41:16 by mbourdel          #+#    #+#             */
/*   Updated: 2015/04/09 03:26:50 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void ft_hud2_print(t_env *env)
{
	char	*s;
	char	*nbr;

	nbr = ft_ftoa(env->value.space);
	s = ft_strjoin("ZOOM : ", nbr);
	mlx_string_put(env->mlx, env->win, 20, 80, WHITE, s);
	free(s);
	free(nbr);
	nbr = ft_ftoa(env->value.height);
	s = ft_strjoin("HEIGHT : ", nbr);
	mlx_string_put(env->mlx, env->win, 20, 100, WHITE, s);
	free(s);
	free(nbr);
	nbr = ft_ftoa(env->value.cst);
	s = ft_strjoin("CONSTANT : ", nbr);
	mlx_string_put(env->mlx, env->win, 20, 120, WHITE, s);
	free(s);
	free(nbr);
}

static void	ft_hud_print(t_env *env)
{
	char	*s;
	char	*nbr;

	nbr = ft_itoa(env->value.alt_max);
	s = ft_strjoin("ALT MAX : ", nbr);
	mlx_string_put(env->mlx, env->win, 20, 40, WHITE, s);
	free(s);
	free(nbr);
	nbr = ft_itoa(env->value.alt_min);
	s = ft_strjoin("ALT MIN : ", nbr);
	mlx_string_put(env->mlx, env->win, 20, 60, WHITE, s);
	free(s);
	free(nbr);
	ft_hud2_print(env);
}

void		ft_print_hud(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 20, 20, WHITE,
		"Press \"ENTER\" to switch on/off the HUD");
	if (env->value.setup == 1)
	{
		ft_hud_print(env);
	}
	return ;
}
