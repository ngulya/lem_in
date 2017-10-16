/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_vuvod_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:36:33 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/05 19:36:33 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_ant	*swap_other_who_start(t_ant *s, t_ant *a)
{
	t_ant	*tmp;
	t_rec	*t;
	t_rec	*tt;

	tmp = s;
	while (tmp && tmp->for_n_l->num != tmp->way->next->num)
	{
		if (tmp == a)
			return (a);
		tmp = tmp->next;
	}
	if (tmp && tmp != a)
	{
		t = tmp->for_n_l;
		tmp->for_n_l = a->for_n_l;
		a->for_n_l = t;
		tt = tmp->way;
		tmp->way = a->way;
		a->way = tt;
	}
	return (tmp ? tmp : a);
}

int		all_go_to_end_from_end(t_ant *as)
{
	t_ant	*a;

	a = as;
	while (a)
	{
		if (a->now)
			return (0);
		a = a->back;
	}
	return (1);
}

void	for_num_of_li(t_ant *end, t_ant *tmp)
{
	tmp = end;
	while (tmp)
	{
		tmp->now = 1;
		tmp->for_n_l = tmp->way;
		tmp = tmp->back;
	}
}

int		number_of_lines(t_ant *end)
{
	t_ant	*tmp;
	int		i;

	i = 0;
	while (!all_go_to_end_from_end(end))
	{
		tmp = end;
		while (tmp)
		{
			if (tmp->for_n_l->num == 1)
				tmp->for_n_l = tmp->for_n_l->next;
			if (tmp->now != 0 && tmp->for_n_l \
				&& free_this_room_back(tmp->for_n_l->num, end))
			{
				tmp->now = tmp->for_n_l->num;
				if (tmp->for_n_l->num != 0)
					tmp->for_n_l = tmp->for_n_l->next;
			}
			tmp = tmp->back;
		}
		i++;
	}
	for_num_of_li(end, tmp);
	return (i);
}
