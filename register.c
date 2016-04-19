/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:28:55 by djoly             #+#    #+#             */
/*   Updated: 2016/04/08 15:36:46 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_add_state(t_lem_env *env)
{
	env->r.state += 1;
	return (1);
}

int		ft_error(t_lem_env *env, int i)
{
	env->r.error = i;
	return (0);
}

int		registre_init(t_lem_registre *r)
{
	r->error = 0;
	r->state = 0;
	r->start = 0;
	r->end = 0;
	r->nbline = 0;
	return (0);
}
