/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_find_all_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 18:59:57 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/05 18:59:57 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	func_del_same(t_rec *res)
{
	t_rec *tmp;

	while (res->next)
	{
		if (res->num == res->next->num)
		{
			tmp = res->next;
			res->next = tmp->next;
			tmp->next->back = res;
			free(tmp);
		}
		res = res->next;
	}
}

void	free_t_rec(t_rec **s)
{
	t_rec	*tmp;

	while (s && *s && (*s)->next)
	{
		tmp = *s;
		*s = (*s)->next;
		free(tmp);
	}
	if (s && *s)
		free(*s);
}

void	first_time_t_rec(t_rec *answer, t_rec *res, t_rec *r)
{
	res->next = NULL;
	res->back = NULL;
	res->num = -1;
	answer->next = NULL;
	answer->back = NULL;
	answer->num = -1;
	r->next = NULL;
	r->num = -1;
	r->back = NULL;
}

void	create_answer(t_rec *ans, int j)
{
	t_rec	*tmp;

	if (ans->num == -1)
		ans->num = j;
	else
	{
		while (ans->next)
			ans = ans->next;
		tmp = ans;
		ans->next = (t_rec *)malloc(sizeof(t_rec));
		ans = ans->next;
		ans->back = tmp;
		ans->num = j;
		ans->next = NULL;
	}
	ans->now = 0;
}

int		find_same_num(t_rec *r, int i)
{
	t_rec	*tmp;

	tmp = r;
	while (tmp)
	{
		if (tmp->num == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
