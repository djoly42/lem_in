/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:19:13 by djoly             #+#    #+#             */
/*   Updated: 2016/04/08 15:35:05 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_start2(t_lem_env *env, char *s)
{
	int		i;

	if (!is_order(env, s) && !is_comment(s))
	{
		i = ft_strlen(s);
		if (*s == '\0' || ft_strcmp("##start", s) == 0 ||
			ft_strcmp("##end", s) == 0)
			return (ft_error(env, 1));
		if (is_room(s))
		{
			while (--i >= 0 && env->tmp != 2)
			{
				if (s[i] == ' ')
					env->tmp += 1;
			}
			i++;
			env->start = ft_strsub(s, 0, i);
			env->r.start = 1;
			return (1);
		}
		else
			return (ft_error(env, 1));
	}
	env->r.nbline += add_file(env, s);
	return (2);
}

int			check_start(t_lem_env *env, char *s)
{
	int		j;
	int		a;

	env->tmp = 0;
	env->r.nbline += add_file(env, s);
	if (env->r.start == 1)
		return (ft_error(env, 2));
	while ((a = get_next_line(0, &s)) > 0)
	{
		if ((j = check_start2(env, s)) == 1)
			break ;
		else if (j == 0)
			return (0);
	}
	env->tmp = 0;
	if (a == 0)
		return (ft_error(env, 1));
	add_room(env, s);
	env->r.nbline += add_file(env, s);
	return (1);
}

static int	check_end2(t_lem_env *env, char *s)
{
	int		i;

	if (!is_order(env, s) && !is_comment(s))
	{
		i = ft_strlen(s);
		if (*s == '\0' || ft_strcmp("##start", s) == 0 ||
			ft_strcmp("##end", s) == 0)
			return (ft_error(env, 1));
		if (is_room(s))
		{
			while (--i >= 0 && env->tmp != 2)
			{
				if (s[i] == ' ')
					env->tmp += 1;
			}
			i++;
			env->end = ft_strsub(s, 0, i);
			env->r.end = 1;
			return (1);
		}
		else
			return (ft_error(env, 1));
	}
	env->r.nbline += add_file(env, s);
	return (2);
}

int			check_end(t_lem_env *env, char *s)
{
	int		a;
	int		j;

	env->tmp = 0;
	env->r.nbline += add_file(env, s);
	if (env->r.end == 1)
		return (ft_error(env, 2));
	while ((a = get_next_line(0, &s)) > 0)
	{
		if ((j = check_end2(env, s)) == 1)
			break ;
		else if (j == 0)
			return (0);
	}
	env->tmp = 0;
	if (a == 0)
		return (ft_error(env, 1));
	add_room(env, s);
	env->r.nbline += add_file(env, s);
	return (1);
}
