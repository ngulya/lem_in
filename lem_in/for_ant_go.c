/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_ant_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:44:08 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/05 18:44:08 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	null_mas(int *mas, int r)
{
	int		i;

	i = 0;
	while (i < r)
		mas[i++] = 0;
}

int		is_disj(t_rec *res, int *mas)
{
	if (res->num == 1)
		res = res->next;
	while (res && res->num != 0)
	{
		if (mas[res->num])
			return (0);
		res = res->next;
	}
	return (1);
}

t_var	*write_data_disj(t_rec **res, int *mas, t_var *al, int i)
{
	if (!is_disj(*res, mas))
	{
		while ((*res) && (*res)->num != 0)
			(*res) = (*res)->next;
		if ((*res))
			(*res) = (*res)->next;
		return (al);
	}
	al = sec_i_s(al);
	al->num = i;
	al->varik = *res;
	if ((*res)->num == 1)
		(*res) = (*res)->next;
	while ((*res) && (*res)->num != 0)
	{
		mas[(*res)->num] = 1;
		(*res) = (*res)->next;
	}
	(*res) = (*res)->next;
	return (al);
}

int		return_num_room(t_rec *s)
{
	int		i;

	i = 0;
	while (s && s->num != 0)
	{
		i++;
		s = s->next;
	}
	if (i != 0)
		i++;
	return (i);
}

t_var	*free_not_good_varik(t_var *al, int i)
{
	t_var	*tmp;
	t_var	*start;

	while (al && al->num != i)
	{
		tmp = al;
		al = al->next;
		tmp->next = NULL;
		free(tmp);
	}
	start = al;
	while (al && al->next && al->num == i && al->next->num == i)
		al = al->next;
	for_free_not_good(al, &tmp);
	al = tmp;
	while (al && al->num != i)
	{
		tmp = al;
		al = al->next;
		tmp->next = NULL;
		free(tmp);
	}
	return (start);
}
