/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabfonction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:10:39 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 11:25:38 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static int	test_room(t_lem_env *env)
{
	int		i;
	int		j;

	i = env->nbroom - 1;
	j = i - 1;
	while (i > 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (ft_strcmp(env->room[i], env->room[j]) == 0)
				return (0);
			j--;
		}
		i--;
	}
	return (1);
}

static int	matrice_visit0(t_lem_env *env, int *i, int *j, int *k)
{
	if (env->r.start == 0 || env->r.end == 0)
		return (ft_error(env, 1));
	if (env->r.state == 1)
	{
		env->room = ft_strsplit(env->str, '\n');
		room_swap(env);
		if (test_room(env) == 0)
			return (ft_error(env, 1));
		matrice_init(env);
		matrice_zero(env);
		visit_init(env);
	}
	*i = 0;
	*j = -1;
	*k = -1;
	return (1);
}

static int	check_link2(t_lem_env *env, char *s, int *i, int *j)
{
	int a;

	a = -1;
	while (s[*i] != '-')
		*i += 1;
	while (++(*j) < env->nbroom)
	{
		if ((a = ft_strncmp(env->room[*j], ft_strsub(s, 0, *i), *i + 1)) == 0)
			break ;
	}
	return (a);
}

int			check_link(t_lem_env *env, char *s)
{
	int		i;
	int		j;
	int		k;
	int		a;

	env->r.nolink = 0;
	if (matrice_visit0(env, &i, &j, &k) == 0)
		return (ft_error(env, 1));
	a = -1;
	if (!is_link(s) || (a = check_link2(env, s, &i, &j)) != 0)
		return (ft_error(env, 2));
	while (++k < env->nbroom)
	{
		if ((a = ft_strcmp(env->room[k], &s[i + 1])) == 0)
			break ;
	}
	if (a != 0 || j == k)
		return (ft_error(env, 2));
	env->matrice[j][k] += 1;
	env->matrice[k][j] += 1;
	if (env->matrice[j][k] == 2)
		return (ft_error(env, 2));
	env->r.nbline += add_file(env, s);
	return (1);
}
