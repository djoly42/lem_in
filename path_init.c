/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:46:38 by djoly             #+#    #+#             */
/*   Updated: 2016/04/12 13:34:51 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		path_malloc(t_lem_env *e)
{
	int	i;

	i = 0;
	if ((e->path = (int **)malloc(sizeof(int *) * 2)) == NULL)
		exit(ft_putstr("ERROR malloc\n"));
	if ((e->path[0] = (int *)malloc(sizeof(int) * e->r.visit[0])) == NULL)
		exit(ft_putstr("ERROR malloc\n"));
	if ((e->path[1] = (int *)malloc(sizeof(int) * e->r.visit[0])) == NULL)
		exit(ft_putstr("ERROR malloc\n"));
	while (i < e->r.visit[0])
	{
		e->path[0][i] = 0;
		e->path[1][i] = 0;
		i++;
	}
	e->path[1][0] = e->nblem;
	return (1);
}

int		path_init(t_lem_env *e)
{
	int		j;
	int		i;
	int		k;
	int		v;

	v = e->r.visit[0];
	j = 0;
	i = 0;
	k = 1;
	path_malloc(e);
	while (j < e->nbroom)
	{
		if (e->matrice[i][j] == 1 && e->r.visit[j] == (v - 1))
		{
			e->path[0][k++] = j;
			i = j;
			v = v - 1;
			j = -1;
		}
		j++;
	}
	return (1);
}
