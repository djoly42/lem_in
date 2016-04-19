/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_ncurses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:30:08 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 18:35:59 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

void	coord_space(t_lem_env *e)
{
	t_room	*tmp;
	t_room	*tmp2;

	tmp = e->beg;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ABS(tmp->x - tmp2->x) < 5) && (ABS(tmp->y - tmp2->y) < 5))
			{
				tmp2->x += 5;
				tmp2->y += 5;
				tmp = e->beg;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int		visu_init(t_lem_env *e)
{
	t_room	*tmp;

	tmp = e->beg;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, e->start) == 0)
			tmp->data = e->nblem;
		else
			tmp->data = 0;
		tmp = tmp->next;
	}
	coord_space(e);
	return (1);
}
