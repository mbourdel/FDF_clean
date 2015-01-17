/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:30:35 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/15 16:37:53 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_set_env(t_env *env)
{
	env->value.space = SPACE;
	env->value.xbegin = XBEGIN;
	env->value.ybegin = YBEGIN;
	env->value.height = HEIGHT;
	env->value.cst = CST;
	env->value.xvar = 0;
	env->value.yvar = 0;
	env->value.setup = 0;
	return ;
}
