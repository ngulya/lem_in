/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vuvod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:34:17 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/05 19:34:17 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_ant	*ant_sta_and_i(t_ant *ant, t_ant *sta, int *i)
{
	if (ant->for_n_l->num == 1)
		ant->for_n_l = ant->for_n_l->next;
	if (ant->now != 0 && ant->for_n_l &&\
		free_this_room(ant->for_n_l->num, sta))
	{
		if (*i != -1 && *i + 1 != ant->num)
			ant = swap_other_who_start(sta, ant);
		*i = ant->num;
		ant->now = ant->for_n_l->num;
		if (ant->for_n_l->num != 0)
			ant->for_n_l = ant->for_n_l->next;
	}
	ant = ant->next;
	return (ant);
}

void	func_sort_ant(t_ant *ant)
{
	t_ant	*sta;
	int		i;

	i = -1;
	sta = ant;
	while (!all_go_to_end(sta))
	{
		ant = sta;
		while (ant)
			ant = ant_sta_and_i(ant, sta, &i);
		i = -1;
		ant = sta;
	}
	ant = sta;
	while (ant)
	{
		ant->now = 1;
		ant->for_n_l = ant->way;
		ant = ant->next;
	}
	ant = sta;
}

void	lets_print(t_ant *ant, t_str *s)
{
	t_ant	*sta;

	sta = ant;
	while (!all_go_to_end(sta))
	{
		ant = sta;
		while (ant)
		{
			if (ant->way->num == 1)
				ant->way = ant->way->next;
			if (ant->now != 0 && ant->way &&\
			free_this_room(ant->way->num, sta))
			{
				ant->now = ant->way->num;
				if (ant->way->num != 0)
					ant->way = ant->way->next;
				write_out_b(ant->num, what_the_s(ant->now, s));
			}
			ant = ant->next;
		}
		ft_putchar('\n');
		ant = sta;
	}
}

t_ant	*optimiation_way(t_ant *ant, t_var *al, t_ant *tmp, t_ant *theend)
{
	int		i;
	int		j;
	t_rec	*for_a;

	while (al)
	{
		ant = tmp;
		while (ant)
		{
			for_a = ant->way;
			i = number_of_lines(theend);
			ant->way = al->varik;
			ant->for_n_l = al->varik;
			j = number_of_lines(theend);
			if (i <= j)
			{
				ant->way = for_a;
				ant->for_n_l = for_a;
			}
			ant = ant->next;
		}
		al = al->next;
	}
	return (tmp);
}

void	vuvod(t_var *al, t_lem *l, t_str *str, t_rec *res)
{
	t_ant	*ant;
	t_var	*at;
	t_rec	*for_a;
	t_ant	*tmp;
	t_ant	*theend;

	at = al;
	ant = malloc_ant(l->ant, &tmp);
	while (ant)
	{
		ant->way = al->varik;
		ant->for_n_l = al->varik;
		for_a = al->varik;
		while (for_a->num != 0)
			for_a = for_a->next;
		theend = ant;
		ant = ant->next;
	}
	ant = optimiation_way(ant, al->next, tmp, theend);
	if (all_room_same_n(al) && !func_most_optimiz(al, ant, theend))
		ant = optimiation_way(ant, al->next, tmp, theend);
	func_sort_ant(tmp);
	lets_print(ant, str);
	free_var_ant(al, ant, res);
	free_lem_str(l, str);
}
