/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:03:46 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 18:36:35 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static void	zero_init(t_lem_env *env)
{
	env->nblem = 0;
	env->nbroom = 0;
	env->tmp = 0;
	env->r.nolink = 1;
	env->r.debug = 0;
	env->r.nofile = 0;
	env->r.visual = 0;
	env->start = 0;
	env->end = 0;
	env->visu = NULL;
	env->beg = NULL;
}

int			main(void)
{
	t_lem_env	env;

	tabfonction_init(&env);
	zero_init(&env);
	env_init(&env);
	if (env.r.error == 1)
		exit(ft_putstr("len-in ERROR\n"));
	if (env.r.debug == 1)
		exit(ft_putstr("debug -> no visu\n"));
	if (env.r.nofile == 1)
		exit(ft_putstr("no file -> no visu\n"));
	visu_init(&env);
	start_visu(&env);
	return (0);
}
