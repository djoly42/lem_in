/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_visu2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:33:49 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 13:35:22 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

char	*line_init(void)
{
	char	*s;

	while (get_next_line(0, &s) > 0)
	{
		if (*s == 'L')
			break ;
	}
	return (s);
}

char	*room_find(t_move_lem *data)
{
	char	*room;

	data->lem = ft_atoi(&(data->s[data->k]));
	while (data->s[data->i] != '-')
		(data->i)++;
	data->j = data->i;
	while (data->s[data->j] != '\0')
	{
		if (data->s[data->j] == ' ')
		{
			data->k = data->j + 2;
			break ;
		}
		(data->j)++;
	}
	room = ft_strsub(data->s, ++(data->i), data->j - data->i);
	return (room);
}

int		room_fill(t_lem_env *e, char *room, int lem)
{
	t_room	*tmp;

	tmp = e->beg;
	while (tmp)
	{
		if (lem == tmp->data)
			tmp->data = 0;
		if (ft_strcmp(room, tmp->name) == 0)
			tmp->data = lem;
		tmp = tmp->next;
	}
	return (1);
}

int		in_while(t_room *room2, int *x, int *y, int *xo)
{
	if (*xo == 0)
	{
		if (*x < room2->x)
			(*x)++;
		else if (*x > room2->x)
			(*x)--;
		*xo = 1;
	}
	else
	{
		if (*y < room2->y)
			(*y)++;
		else if (*y > room2->y)
			(*y)--;
		*xo = 0;
	}
	return (1);
}

int		print_link3(t_room *room1, t_room *room2)
{
	int		x;
	int		y;
	int		xo;

	x = room1->x;
	y = room1->y;
	xo = 0;
	while (x != room2->x || y != room2->y)
	{
		in_while(room2, &x, &y, &xo);
		mvprintw(x, y, "+");
	}
	return (1);
}
