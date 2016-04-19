/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 14:23:30 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 10:05:50 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			print_cycle(t_lem_env *e)
{
	int		i;

	i = 1;
	while (i < e->r.visit[0] - 1)
	{
		if (e->path[1][i] != 0)
		{
			if (e->path[1][i + 1] == 0)
				ft_printf("L%d-%s", e->path[1][i], e->room[e->path[0][i]]);
			else
				ft_printf("L%d-%s ", e->path[1][i], e->room[e->path[0][i]]);
		}
		i++;
	}
	if (e->path[1][i] != 0)
		ft_printf("L%d-%s", e->path[1][i], e->room[e->path[0][i]]);
	ft_putchar('\n');
	return (1);
}

int			resolve(t_lem_env *e)
{
	int		i;

	while (e->path[1][e->r.visit[0] - 1] < e->nblem)
	{
		i = e->r.visit[0];
		while (i > 0)
		{
			if (e->path[1][i] != e->path[1][i - 1])
			{
				e->path[1][i] = e->path[1][i] + 1;
				if (e->path[1][i] == e->nblem)
					e->path[1][i - 1] = 0;
			}
			i--;
		}
		print_cycle(e);
	}
	return (1);
}
