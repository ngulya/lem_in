/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_vuvod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:32:53 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/05 19:32:54 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_ant	*malloc_ant(int a, t_ant **aaa)
{
	t_ant	*ret;
	t_ant	*tmp;
	t_ant	*ant;

	ant = (t_ant *)malloc(sizeof(t_ant));
	ret = ant;
	ant->next = NULL;
	ant->back = NULL;
	ant->num = 1;
	ant->now = 1;
	while (ant->num < a)
	{
		ant->next = (t_ant *)malloc(sizeof(t_ant));
		tmp = ant;
		ant = ant->next;
		ant->back = tmp;
		ant->next = NULL;
		ant->now = 1;
		ant->num = tmp->num + 1;
	}
	*aaa = ret;
	return (ret);
}

int		all_go_to_end(t_ant *ss)
{
	t_ant	*ant;

	ant = ss;
	while (ant)
	{
		if (ant->now)
			return (0);
		ant = ant->next;
	}
	return (1);
}

int		free_this_room(int i, t_ant *s)
{
	if (i == 0)
		return (1);
	while (s)
	{
		if (s->now == i)
			return (0);
		s = s->next;
	}
	return (1);
}

int		free_this_room_back(int i, t_ant *s)
{
	if (i == 0)
		return (1);
	while (s)
	{
		if (s->now == i)
			return (0);
		s = s->back;
	}
	return (1);
}

char	*what_the_s(int i, t_str *s)
{
	int		j;

	j = 0;
	if (i == 1)
		return (s->str);
	if (i == 0)
		return (s->next->str);
	while (j < i)
	{
		s = s->next;
		j++;
	}
	return (s->str);
}
