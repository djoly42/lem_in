/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_booleen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 15:13:07 by djoly             #+#    #+#             */
/*   Updated: 2016/04/14 13:08:10 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int			is_order(t_lem_env *e, char *s)
{
	if (ft_strcmp("##visual", s) == 0)
		e->r.visual = 1;
	else if (ft_strcmp("##debug", s) == 0)
		e->r.debug = 1;
	else if (ft_strcmp("##nofile", s) == 0)
		e->r.nofile = 1;
	else
		return (0);
	return (1);
}

int			is_comment(char *s)
{
	if (*s == '#')
	{
		if (ft_strcmp("##start", s) == 0 || ft_strcmp("##end", s) == 0)
			return (0);
		return (1);
	}
	return (0);
}

int			is_nblem(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] < '0' || s[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int			ft_return(t_lem_env *env, char *s)
{
	env->last = s;
	return (-1);
}

int			ft_comment(t_lem_env *env, char *s)
{
	env->last = s;
	return (0);
}
