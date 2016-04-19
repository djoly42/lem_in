/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:59:04 by djoly             #+#    #+#             */
/*   Updated: 2016/04/08 15:35:27 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		add_file(t_lem_env *env, char *s)
{
	char	*tmp;
	char	*tmp2;

	if (env->r.nbline == 0)
		env->file = ft_strjoin(s, "\n");
	else
	{
		tmp = ft_strjoin(env->file, s);
		tmp2 = ft_strjoin(tmp, "\n");
		free(tmp);
		free(env->file);
		env->file = tmp2;
	}
	return (1);
}

int		visit_init(t_lem_env *env)
{
	if ((env->r.visit = (int *)malloc(sizeof(int) * env->nbroom)) == NULL)
		exit(ft_putstr("ERROR malloc\n"));
	return (1);
}

int		matrice_zero(t_lem_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nbroom)
	{
		j = 0;
		while (j < env->nbroom)
		{
			env->matrice[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int		matrice_init(t_lem_env *env)
{
	int		i;

	i = 0;
	env->matrice = (int **)malloc(sizeof(int *) * env->nbroom);
	while (i < env->nbroom)
	{
		env->matrice[i] = (int *)malloc(sizeof(int) * env->nbroom);
		i++;
	}
	return (1);
}
