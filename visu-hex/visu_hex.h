/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 18:19:28 by djoly             #+#    #+#             */
/*   Updated: 2016/04/15 16:40:12 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_HEX_H
# define VISU_HEX_H
# include <ncurses.h>
# include "../Libft/libft.h"
# include "../Libft/ft_printf.h"
# include "../Libft/get_next_line.h"
# define ABS(n) ((n) < 0 ? -(n) : (n))

typedef struct s_visu_hex	t_visu_hex;
struct	s_visu_hex
{
	int		nblem;
	int		nbroom;
	char	*start;
	char	*end;
	char	**room;
};

typedef struct s_move_lem	t_move_lem;
struct	s_move_lem
{
	int		i;
	int		j;
	int		k;
	int		lem;
	char	*s;
	char	*room;
};

typedef struct s_room	t_room;
struct	s_room
{
	char	*name;
	int		data;
	int		x;
	int		y;
	t_room	*next;
};

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
	t_room			*tmpr;
	t_room			*beg;
	t_room			*visu;
	int				nblem;
	int				(*fonction[6])(t_lem_env *env, char *s);
	char			*start;
	int				*coord_start;
	char			*end;
	int				*coord_end;
	int				nbroom;
	char			*str;
	char			**room;
	char			*coordstr;
	int				**coord;
	int				**matrice;
	char			*last;
	int				**path;

};

int		coord_start(char *s, int i, t_lem_env *env);
int		coord_end(char *s, int i, t_lem_env *env);
int		coord(char *s, int i, t_lem_env *env);
int		visu_init(t_lem_env *e);
void	start_visu(t_lem_env *e);
char	*line_init(void);
int		print_link3(t_room *room1, t_room *room2);
int		room_fill(t_lem_env *e, char *room, int lem);
char	*room_find(t_move_lem *data);

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
