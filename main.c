/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:03:46 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 15:48:26 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
}

int			main(void)
{
	t_lem_env	env;

	tabfonction_init(&env);
	zero_init(&env);
	env_init(&env);
	if (env.r.debug == 1)
		debug1(&env);
	if (env.r.error == 1)
		exit(ft_putstr("ERROR\n"));
	if (!find_path(&env))
		exit(ft_putstr("ERROR\n"));
	if (!path_init(&env))
		exit(ft_putstr("ERROR\n"));
	if (env.r.debug == 1)
		debug2(&env);
	if (!env.r.nofile)
		ft_printf("%s\n", env.file);
	else
		ft_putstr("##nofile\n");
	if (!resolve(&env))
		exit(ft_putstr("ERROR\n"));
	return (0);
}
