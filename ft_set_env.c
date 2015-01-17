/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourdel <mbourdel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 17:30:35 by mbourdel          #+#    #+#             */
/*   Updated: 2015/01/17 14:41:21 by mbourdel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_set_env(t_env *env)
{
	env->value.proj = 0;
	env->value.space = SPACE;
	env->value.xbegin = XBEGIN;
	env->value.ybegin = YBEGIN;
	env->value.height = HEIGHT;
	env->value.cst = CST1;
	env->value.cst2 = CST2;
	env->value.xvar = 0;
	env->value.yvar = 0;
	env->value.setup = 0;
	return ;
}
