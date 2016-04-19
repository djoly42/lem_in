/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 10:54:47 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 13:41:14 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int		tmp_init_start(t_lem_env *env, t_room *tmp, int i, char *s)
{
	tmp->next = NULL;
	tmp->name = env->end;
	tmp->x = ft_atoi(&s[i]);
	i = ft_strlen(s);
	return (i);
}

int		tmp_init_end(t_lem_env *env, t_room *tmp, int i, char *s)
{
	tmp->next = NULL;
	tmp->name = env->end;
	tmp->x = ft_atoi(&s[i]);
	i = ft_strlen(s);
	return (i);
}

int		coord_start(char *s, int i, t_lem_env *env)
{
	t_room		*tmp;

	if ((tmp = (t_room *)malloc(sizeof(t_room))) == NULL)
		exit(ft_putstr("ERROR Malloc\n"));
	i = tmp_init_start(env, tmp, i, s);
	while (--i >= 0)
	{
		if (s[i] == ' ')
			break ;
	}
	tmp->y = ft_atoi(&s[i]);
	if (env->visu == NULL)
	{
		env->visu = tmp;
		env->beg = env->visu;
	}
	else
	{
		while (env->visu->next)
			env->visu = env->visu->next;
		env->visu->next = tmp;
		env->visu = env->beg;
	}
	return (1);
}

int		coord_end(char *s, int i, t_lem_env *env)
{
	t_room		*tmp;

	if ((tmp = (t_room *)malloc(sizeof(t_room))) == NULL)
		exit(ft_putstr("ERROR Malloc\n"));
	i = tmp_init_end(env, tmp, i, s);
	while (--i >= 0)
	{
		if (s[i] == ' ')
			break ;
	}
	if (env->visu == NULL)
	{
		env->visu = tmp;
		env->beg = env->visu;
	}
	else
	{
		while (env->visu->next)
			env->visu = env->visu->next;
		env->visu->next = tmp;
		env->visu = env->beg;
	}
	tmp->y = ft_atoi(&s[i]);
	return (1);
}
