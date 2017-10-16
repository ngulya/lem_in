/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:17:24 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/05 12:17:25 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	func_create_link_from(t_rec *new, int one, int two, int i)
{
	create_answer(new, i);
	create_answer(new, one);
	create_answer(new, two);
}

int		mass_rec_two(t_lem *l, int j, t_rec *r, t_rec *ans)
{
	int		i;
	int		t;

	t = 0;
	i = 0;
	if (j >= 0 && l->mas[1][j])
	{
		create_answer(ans, -13);
		return (1);
	}
	i = 1;
	while (i < l->rooms)
	{
		if (l->mas[i][j] && !find_same_num(r, i))
		{
			create_answer(r, i);
			if (mass_rec_two(l, i, r, ans))
			{
				t++;
				create_answer(ans, i);
			}
		}
		i++;
	}
	return (t);
}

int		mass_rec(t_lem *l, int j, t_rec *r, t_rec *ans)
{
	int		i;
	int		t;
	t_rec	*tmp;

	t = 0;
	if (for_mas_rec(ans, j, &i, l))
		return (1);
	while (i < l->rooms)
	{
		if (l->mas[i][j] && !find_same_num(r, i))
		{
			if (!find_same_num(r, i))
				create_answer(r, j);
			tmp = r;
			create_answer(r, i);
			if (mass_rec_two(l, i, r, ans) && (++t || !t))
				func_create_link_from(ans, i, j, -69);
			free_t_rec(&(tmp->next));
			tmp->next = NULL;
		}
		i++;
	}
	return (t);
}

int		start_logic(t_lem *lem, t_rec *res, t_rec *answer)
{
	int		t;
	int		j;

	t = 0;
	j = 2;
	if (lem->mas[0][1])
	{
		create_answer(answer, 1);
		create_answer(answer, 0);
		return (1);
	}
	while (j < lem->rooms)
	{
		if (lem->mas[0][j])
		{
			if (mass_rec(lem, j, res, answer))
				t++;
		}
		j++;
	}
	return (t);
}

t_rec	*find_all_way(t_str *str, t_lem *lem)
{
	t_rec	*r;
	t_rec	*answer;
	t_rec	*res;
	t_rec	*tmp;

	r = (t_rec *)malloc(sizeof(t_rec));
	answer = (t_rec *)malloc(sizeof(t_rec));
	res = (t_rec *)malloc(sizeof(t_rec));
	first_time_t_rec(answer, res, r);
	if ((lem->rooms > 2) && !start_logic(lem, r, answer))
	{
		free_t_rec(&r);
		free_t_rec(&answer);
		free_t_rec(&res);
		error_fn(lem, NULL, str);
	}
	free_t_rec(&r);
	tmp = answer;
	while (answer->next)
		answer = answer->next;
	create_link_way(res, answer);
	free_t_rec(&tmp);
	func_del_same(res);
	return (res);
}
