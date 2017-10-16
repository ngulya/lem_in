/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_go_go_go.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:31:47 by ngulya            #+#    #+#             */
/*   Updated: 2017/05/12 16:32:00 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	my_norm_fuc_u(t_var *al, t_lem *l)
{
	t_var	*al2;

	al2 = al;
	while (al2)
	{
		al2->num_room = return_num_room(al2->varik);
		al2 = al2->next;
	}
	while (!sort_ways(al))
	{
		al2 = al;
		while (al2->next)
		{
			if (al2->num_room > al2->next->num_room)
				swapp(al2, al2->next);
			al2 = al2->next;
		}
	}
	print_map(l->map);
}

void	func_stion_agg(t_var *al, t_lem *l, int *mas)
{
	al->next = NULL;
	al->num_ways = 0;
	al->num = -1;
	al->num_room = 0;
	null_mas(mas, l->rooms);
}

void	ses_ant_g_g(t_rec *res, int *mas, t_var *al, t_lem *l)
{
	int		i;
	t_rec	*tmp;

	tmp = res;
	i = 1;
	while (tmp)
	{
		res = tmp;
		while (res)
			al = write_data_disj(&res, mas, al, i);
		null_mas(mas, l->rooms);
		while (tmp && tmp->num != 0)
			tmp = tmp->next;
		if (tmp)
			tmp = tmp->next;
		i++;
	}
}

void	ants_go_go_go(t_rec *res, t_lem *l, t_str *s)
{
	t_var	*al;
	t_var	*al2;
	t_rec	*tmp;
	int		mas[l->rooms];

	tmp = res;
	al = (t_var *)malloc(sizeof(t_var));
	func_stion_agg(al, l, mas);
	ses_ant_g_g(res, mas, al, l);
	al2 = al;
	al = find_big_num(al2);
	my_norm_fuc_u(al, l);
	vuvod(al, l, s, res);
}
