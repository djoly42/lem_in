/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 16:39:04 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 13:35:20 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int		print_link2(int i, int j, t_lem_env *e)
{
	t_room *room1;
	t_room *room2;
	t_room *tmp;

	tmp = e->beg;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, e->room[i]) == 0)
			room1 = tmp;
		if (ft_strcmp(tmp->name, e->room[j]) == 0)
			room2 = tmp;
		tmp = tmp->next;
	}
	print_link3(room1, room2);
	return (1);
}

int		print_link(t_lem_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < e->nbroom)
	{
		j = i;
		while (j < e->nbroom)
		{
			if (e->matrice[i][j] == 1)
				print_link2(i, j, e);
			j++;
		}
		i++;
	}
	return (1);
}

void	move_lem_init(t_move_lem *data)
{
	data->i = 0;
	data->j = 0;
	data->k = 1;
	data->lem = 0;
	data->s = line_init();
}

int		move_lem(t_lem_env *e)
{
	t_move_lem	d;

	move_lem_init(&d);
	if (d.s == NULL)
		return (0);
	while (d.s[d.j] != '\0')
	{
		d.room = room_find(&d);
		room_fill(e, d.room, d.lem);
	}
	return (1);
}

void	start_visu(t_lem_env *e)
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	while (1)
	{
		print_link(e);
		mvprintw(1, COLS / 2, "Fourmiliere de WTF");
		e->tmpr = e->beg;
		while (e->tmpr)
		{
			mvprintw(e->tmpr->x - 1, e->tmpr->y, " %s", e->tmpr->name);
			if (e->tmpr->data != 0)
				attron(COLOR_PAIR(1));
			mvprintw(e->tmpr->x, e->tmpr->y, "[%d]", e->tmpr->data);
			if (e->tmpr->data != 0)
				attroff(COLOR_PAIR(1));
			e->tmpr = e->tmpr->next;
		}
		refresh();
		sleep(1);
		clear();
		if (move_lem(e) == 0)
			break ;
	}
	endwin();
}
