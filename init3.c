/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 16:22:18 by djoly             #+#    #+#             */
/*   Updated: 2016/04/12 11:23:43 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		room_swap(t_lem_env *e)
{
	char	*tmp;
	int		i;

	if (ft_strcmp(e->room[0], e->start) != 0)
	{
		tmp = e->room[0];
		e->room[0] = e->start;
		i = 1;
		while (ft_strcmp(e->room[i], e->start) != 0)
			i++;
		e->room[i] = tmp;
	}
	if (ft_strcmp(e->room[e->nbroom - 1], e->end) != 0)
	{
		tmp = e->room[e->nbroom - 1];
		e->room[e->nbroom - 1] = e->end;
		i = 1;
		while (ft_strcmp(e->room[i], e->end) != 0)
			i++;
		e->room[i] = tmp;
	}
	return (1);
}
