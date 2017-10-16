/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_ant_go_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:46:43 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/05 18:46:43 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		find_most_prety_vari(t_var *tmp)
{
	int		i;
	int		n_w;
	int		n_r;

	i = 1;
	n_r = tmp->num_room;
	n_w = tmp->num_ways;
	while (tmp)
	{
		if (tmp->num_room != 0 && (tmp->num_ways > n_w \
			|| (tmp->num_ways == n_w && tmp->num_room < n_r)))
		{
			i = tmp->num;
			n_r = tmp->num_room;
			n_w = tmp->num_ways;
		}
		tmp = tmp->next;
	}
	return (i);
}

t_var	*find_big_num(t_var *al2)
{
	int		i;
	t_var	*tmp;
	t_var	*al;

	al = al2;
	tmp = al2;
	i = 1;
	while (al)
	{
		while (al && al->num == i)
		{
			tmp->num_ways++;
			tmp->num_room = tmp->num_room + return_num_room(al->varik);
			al = al->next;
		}
		i++;
		tmp = al;
	}
	return (free_not_good_varik(al2, find_most_prety_vari(al2)));
}

int		sort_ways(t_var *al)
{
	t_var	*tmp;

	tmp = al;
	while (tmp->next)
	{
		if (tmp->num_room > tmp->next->num_room)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	swapp(t_var *o, t_var *t)
{
	int		n_r;
	int		n_w;
	t_rec	*var;

	var = o->varik;
	n_r = o->num_room;
	n_w = o->num_ways;
	o->varik = t->varik;
	o->num_room = t->num_room;
	o->num_ways = t->num_ways;
	t->varik = var;
	t->num_room = n_r;
	t->num_ways = n_w;
}

void	print_map(t_str *map)
{
	t_str	*tmp;

	tmp = map;
	while (tmp)
	{
		ft_putstr(tmp->str);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
