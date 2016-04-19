/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 20:56:26 by djoly             #+#    #+#             */
/*   Updated: 2016/04/14 13:09:02 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int		rec_path(t_lem_env *e, int a, int i)
{
	int		j;

	j = e->nbroom - 1;
	while (j >= 0)
	{
		if (e->matrice[i][j] == 1 && (e->r.visit[j] > a ||
			e->r.visit[j] == 0) && j != i)
		{
			e->r.visit[j] = a;
			rec_path(e, a + 1, j);
		}
		j--;
	}
	return (1);
}

int		test_start(t_lem_env *e)
{
	if (e->r.visit[0] == 0)
		return (0);
	return (1);
}

int		test_end(t_lem_env *e)
{
	int		ret;
	int		i;
	int		j;

	i = e->nbroom - 1;
	j = e->nbroom - 1;
	ret = 0;
	while (j >= 0)
	{
		if (e->matrice[i][j] == 1)
			ret = 1;
		j--;
	}
	return (ret);
}

int		find_path(t_lem_env *e)
{
	int		i;
	int		j;

	i = e->nbroom - 1;
	j = e->nbroom - 1;
	if (test_end(e) == 0)
		return (0);
	e->r.visit[i] = 1;
	while (j >= 0)
	{
		if (e->matrice[i][j] == 1 && i != j)
		{
			e->r.visit[j] = 2;
			rec_path(e, 3, j);
		}
		j--;
	}
	if (test_start(e) == 0)
		return (0);
	return (1);
}
