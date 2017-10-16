/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_vuvod_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:23:08 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/08 14:23:08 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		all_room_same_n(t_var *al)
{
	t_var	*a;
	t_rec	*r;
	int		i;

	a = al;
	i = 0;
	while (a)
	{
		r = a->varik;
		a->num_ways = 0;
		while (r && r->num != 0)
		{
			a->num_ways++;
			r = r->next;
		}
		if (i != 0 && i != a->num_ways)
			return (0);
		i = a->num_ways;
		a = a->next;
	}
	return (1);
}

int		func_most_optimiz(t_var *al, t_ant *ant, t_ant *theend)
{
	int		first;
	int		second;
	t_ant	*tmp;
	t_var	*a;

	first = number_of_lines(theend);
	tmp = ant;
	while (tmp)
	{
		a = al;
		while (a && tmp)
		{
			tmp->way = a->varik;
			tmp->for_n_l = a->varik;
			tmp = tmp->next;
			a = a->next;
		}
	}
	second = number_of_lines(theend);
	if (first < second)
		return (0);
	return (1);
}
