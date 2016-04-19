/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 09:56:48 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 11:37:08 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

int		find_nblem(t_visu_hex *hex)
{
	int		a;

	while ((a = get_next_line(0, &s)) > 0)
	{
		if (*s != '#')
		{
			hex->nblem = ft_atoi(s);
			return (1);
		}
	}
	return (0);
}

int		find_start(t_visu_hex *hex)
{
	int		a;
	char	*s;

	while ((a = get_next_line(0, &s)) > 0)
	{
		if (*s != '#')
		{
			hex->start = s;
			return (1);
		}
	}
	return (0);
}

int		find_room(t_visu_hex *hex)
{
	int		a;

	while ((a = get_next_line(0, &s)) > 0)
	{
		if (ft_strcmp("##start", s) == 0)
			find_start(hex);
		else if (ft_strcmp("##end", s) == 0)
			find_end(hex);
	}
	return (0);
}
