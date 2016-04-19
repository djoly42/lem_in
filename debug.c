/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:11:18 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 14:26:30 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_path(t_lem_env *env)
{
	int	i;

	i = 0;
	while (i < env->r.visit[0])
	{
		ft_printf("%d\t", env->path[0][i]);
		i++;
	}
	i = 0;
	ft_printf("\n");
	while (i < env->r.visit[0])
	{
		ft_printf("%s\t", env->room[env->path[0][i]]);
		i++;
	}
	i = 0;
	ft_printf("\n");
	while (i < env->r.visit[0])
	{
		ft_printf("%d\t", env->path[1][i]);
		i++;
	}
	ft_printf("\n");
}

void		debug1(t_lem_env *env)
{
	int		a;
	int		i;

	a = 0;
	ft_printf("##debug\nerror=%d\nstart=%s\nend=%s\nnbroom=%d\nstr=%s\n",
				env->r.error, env->start, env->end, env->nbroom, env->str);
	if (env->r.error == 1)
		return ;
	while (a < env->nbroom)
	{
		ft_printf("room[%d]=%s\n", a, env->room[a]);
		a++;
	}
	i = 0;
	ft_printf("matrice\n");
	while (i < env->nbroom)
	{
		a = 0;
		while (a < env->nbroom)
			ft_printf("%d ", env->matrice[i][a++]);
		ft_printf("\n");
		i++;
	}
}

void		debug2(t_lem_env *env)
{
	int		i;

	i = 0;
	while (i < env->nbroom)
	{
		ft_printf("visit[%d]=%d\n", i, env->r.visit[i]);
		i++;
	}
	ft_putstr("path:\n");
	print_path(env);
	if (env->r.nofile == 0)
		ft_putstr("FILE:\n=====================================\n");
}
