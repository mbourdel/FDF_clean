/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:52:16 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/23 19:09:59 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	t_env		env;

	ft_set_env(&env);
	if (ac != 2)
		ft_putstr("ERROR: invalid arguments\n");
	else if ((env.fd = open(av[1], O_RDONLY)) < 0)
		ft_putstr("ERROR: invalid arguments\n");
	else if ((env.fd = open(av[1], O_RDONLY)) < 0)
		ft_putstr("ERROR: invalid arguments\n");
	else if (ft_map(&env))
		ft_putendl("ERROR: invalid map");
	else if (!(env.mlx = mlx_init()))
		ft_putendl("Are you FUCKING kidding me ?\nenv -i is for the weak LOL");
	else
	{
		ft_altitude(&env);
		env.win = mlx_new_window(env.mlx, XWIN_SIZE, YWIN_SIZE, av[1]);
		ft_img(&env);
		mlx_key_hook(env.win, key_hook, &env);
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}
