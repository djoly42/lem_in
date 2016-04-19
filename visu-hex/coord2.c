/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:40:26 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 13:41:06 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int		tmp_init(t_room *tmp, int i, char *s)
{
	tmp->next = NULL;
	tmp->name = ft_strsub(s, 0, i);
	tmp->x = ft_atoi(&s[i]);
	i = ft_strlen(s);
	return (i);
}

int		coord(char *s, int i, t_lem_env *env)
{
	t_room		*tmp;

	if ((tmp = (t_room *)malloc(sizeof(t_room))) == NULL)
		exit(ft_putstr("ERROR Malloc\n"));
	i = tmp_init(tmp, i, s);
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
