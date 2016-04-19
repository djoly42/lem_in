/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:45:41 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 10:06:20 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "Libft/libft.h"
# include "Libft/ft_printf.h"
# include "Libft/get_next_line.h"
# include <stdlib.h>

typedef struct s_lem_registre	t_lem_registre;
struct	s_lem_registre
{
	int		visual;
	int		nolink;
	int		debug;
	int		nofile;
	int		error;
	int		state;
	int		start;
	int		end;
	int		*visit;
	int		nbline;
};

typedef struct s_lem_env	t_lem_env;
struct	s_lem_env
{
	int				tmp;
	char			*file;
	t_lem_registre	r;
	int				nblem;
	int				(*fonction[6])(t_lem_env *env, char *s);
	char			*start;
	char			*end;
	int				nbroom;
	char			*str;
	char			**room;
	int				**matrice;
	char			*last;
	int				**path;

};

int		add_room(t_lem_env *env, char *s);
int		add_file(t_lem_env *env, char *s);
int		env_init(t_lem_env *env);
int		check_end(t_lem_env *env, char *s);
int		check_nblem(t_lem_env *env, char *s);
int		check_link(t_lem_env *env, char *s);
int		check_room(t_lem_env *env, char *s);
int		check_start(t_lem_env *env, char *s);
void	debug1(t_lem_env *e);
void	debug2(t_lem_env *e);
int		find_path(t_lem_env *env);
int		ft_add_state(t_lem_env *env);
int		ft_error(t_lem_env *env, int i);
int		ft_return(t_lem_env *env, char *s);
int		matrice_init(t_lem_env *env);
int		matrice_zero(t_lem_env *env);
int		path_init(t_lem_env *e);
int		print_cycle(t_lem_env *e);
void	print_path(t_lem_env *env);
int		is_comment(char *s);
int		is_link(char *s);
int		is_nblem(char *s);
int		is_order(t_lem_env *e, char *s);
int		is_room(char *s);
int		room_swap(t_lem_env *e);
int		registre_init(t_lem_registre *registre);
int		resolve(t_lem_env *e);
void	tabfonction_init(t_lem_env *env);
int		visit_init(t_lem_env *env);

#endif
