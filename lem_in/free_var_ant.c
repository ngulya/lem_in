/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_var_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 15:14:06 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/05 15:14:06 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	freshum_str(t_str *str)
{
	t_str	*s;

	while (str)
	{
		s = str;
		str = str->next;
		if (s->str)
			free(s->str);
		free(s);
	}
}

void	free_lem_str(t_lem *l, t_str *str)
{
	t_str	*s;
	int		i;

	i = 0;
	if (l)
	{
		while (l->mas && i < l->rooms)
			free(l->mas[i++]);
		free(l->mas);
		while (l->map)
		{
			s = l->map;
			l->map = l->map->next;
			free(s->str);
			free(s);
		}
		free(l);
	}
	freshum_str(str);
}

void	free_var_ant(t_var *a, t_ant *b, t_rec *res)
{
	t_var	*al;
	t_ant	*bl;
	t_rec	*tmp;

	while (a)
	{
		al = a;
		a = a->next;
		free(al);
	}
	while (b)
	{
		bl = b;
		b = b->next;
		free(bl);
	}
	while (res && res->next)
	{
		tmp = res;
		res = res->next;
		free(tmp);
	}
	free(res);
}
