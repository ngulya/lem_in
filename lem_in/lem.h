/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 14:41:20 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 14:41:20 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H

# include "libft/libft.h"

typedef struct		s_str
{
	int				one;
	char			*str;
	struct s_str	*next;
}					t_str;

typedef struct		s_rec
{
	int				num;
	int				now;
	struct s_rec	*next;
	struct s_rec	*back;
}					t_rec;

typedef struct
{
	int				rooms;
	int				ant;
	t_str			*map;
	int				**mas;
}					t_lem;

typedef struct		s_var
{
	int				num;
	int				num_ways;
	int				num_room;
	struct s_rec	*varik;
	struct s_var	*next;
}					t_var;

typedef struct		s_ant
{
	int				num;
	int				now;
	int				str;
	struct s_rec	*way;
	struct s_rec	*for_n_l;
	struct s_ant	*next;
	struct s_ant	*back;
}					t_ant;

void				create_map(t_lem *lem, char *line);
void				error_fn(t_lem *l, char *line, t_str *str);
int					size_name_room(char *line, t_str *s, t_lem *lem);
int					correct_link(char *line, t_str *s);
int					all_room(t_str *s, t_lem *lem, char *line);
void				write_str(t_str **s, int *one, char *line, int i);
char				*start_end(char *line, int *one, t_lem *lem, t_str *str);
int					one_start_one_end(t_str *st);
void				matrix_func(t_str *s, t_lem *l, char *line, int rooms);
int					dop_dop_function_write(t_str *tmp, char *line, int minus);
t_rec				*find_all_way(t_str *str, t_lem *lem);
void				create_link_way(t_rec *new, t_rec *tmp);
void				create_answer(t_rec *ans, int j);
void				func_create_link_from(t_rec *new, int one, int two, int i);
void				ants_go_go_go(t_rec *res, t_lem *l, t_str *s);
void				vuvod(t_var *al, t_lem *l, t_str *str, t_rec *res);
void				free_var_ant(t_var *a, t_ant *b, t_rec *res);
void				free_lem_str(t_lem *l, t_str *str);
void				null_mas(int *mas, int r);
int					is_disj(t_rec *res, int *mas);
t_var				*write_data_disj(t_rec **res, int *mas, t_var *al, int i);
int					return_num_room(t_rec *s);
t_var				*free_not_good_varik(t_var *al, int i);
int					find_most_prety_vari(t_var *tmp);
t_var				*find_big_num(t_var *al2);
int					sort_ways(t_var *al);
void				print_map(t_str *map);
void				swapp(t_var *o, t_var *t);
void				func_del_same(t_rec *res);
void				free_t_rec(t_rec **s);
void				first_time_t_rec(t_rec *answer, t_rec *res, t_rec *r);
int					find_same_num(t_rec *r, int i);
int					for_mas_rec(t_rec *ans, int j, int *i, t_lem *l);
t_var				*sec_i_s(t_var *al);
void				for_free_not_good(t_var *al, t_var **tmp);
t_ant				*malloc_ant(int a, t_ant **aaa);
int					all_go_to_end(t_ant *ss);
int					free_this_room(int i, t_ant *s);
int					free_this_room_back(int i, t_ant *s);
char				*what_the_s(int i, t_str *s);
int					number_of_lines(t_ant *end);
t_ant				*swap_other_who_start(t_ant *s, t_ant *a);
char				*ft_strndup(const char *s1, int i);
void				write_out_b(int num, char *s);
int					all_room_same_n(t_var *al);
int					func_most_optimiz(t_var *al, t_ant *ant, t_ant *theend);

#endif
