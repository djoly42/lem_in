/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:58:49 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 11:27:59 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static int	is_room2(int i, char *s)
{
	while (s[++i] != ' ')
	{
		if ((s[i] < '0' || s[i] > '9') || s[i] == '\0')
			return (0);
	}
	if (s[++i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if ((s[i] < '0' || s[i] > '9') || s[i++] == '\0')
			return (0);
	}
	return (1);
}

int			is_room(char *s)
{
	int i;
	int nbspace;

	i = -1;
	nbspace = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == ' ')
			nbspace++;
	}
	if (nbspace == 0)
		return (0);
	i = -1;
	if (*s == 'L')
		return (0);
	while (nbspace >= 2)
	{
		i++;
		if (s[i] == '-' || s[i] == '\0')
			return (0);
		if (s[i] == ' ')
			nbspace--;
	}
	return (is_room2(i, s));
}

int			is_link(char *s)
{
	int i;

	i = -1;
	while (s[++i] != '-')
	{
		if (s[i] == '\0')
			return (0);
	}
	i = -1;
	if (*s == 'L' || *s == '#' || *s == '\0')
		return (0);
	while (s[++i] != '-')
	{
		if (s[i] == '\0')
			return (0);
	}
	if (s[++i] == 'L' || s[i] == '#' || s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '-' || s[i++] == '\0')
			return (0);
	}
	return (1);
}

void		tabfonction_init(t_lem_env *env)
{
	registre_init(&env->r);
	env->fonction[0] = check_nblem;
	env->fonction[1] = check_room;
	env->fonction[2] = check_link;
	env->fonction[3] = ft_return;
}

int			env_init(t_lem_env *env)
{
	int		a;
	char	*s;

	while ((a = get_next_line(0, &s)) > 0)
	{
		if (*s == '\n')
			return (ft_error(env, 1));
		if (!is_order(env, s) && !is_comment(s))
			env->fonction[env->r.state](env, s);
		else
			env->r.nbline += add_file(env, s);
		if (env->r.error)
			return (0);
	}
	if (env->r.nolink)
		return (ft_error(env, 1));
	return (1);
}
