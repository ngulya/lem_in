/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:14:17 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 17:14:17 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	write_str(t_str **s, int *one, char *line, int i)
{
	if ((*s)->one == -69 && i)
	{
		(*s)->str = ft_strndup(line, i);
		(*s)->one = *one;
	}
	else if (i)
	{
		(*s)->next = (t_str *)malloc(sizeof(t_str));
		(*s) = (*s)->next;
		(*s)->next = NULL;
		(*s)->str = ft_strndup(line, i);
		(*s)->one = *one;
	}
	*one = 0;
}

char	*start_end(char *line, int *one, t_lem *lem, t_str *str)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	if (*line == '#' && *(line + 1) == '#')
	{
		create_map(lem, line);
		if (!ft_strcmp("##start", line) && !x)
		{
			x++;
			*one = 1;
		}
		else if (!ft_strcmp("##end", line) && !y)
		{
			y++;
			*one = -1;
		}
		else if ((!ft_strcmp("##start", line) && x)\
		|| (!ft_strcmp("##end", line) && y))
			error_fn(lem, line, str);
		free(line);
		get_next_line(0, &line);
	}
	return (line);
}

int		one_start_one_end(t_str *st)
{
	t_str	*tmp;
	int		s;
	int		e;

	s = 0;
	e = 0;
	tmp = st;
	while (tmp)
	{
		if (tmp->one == 1)
			s = tmp->one + s;
		if (tmp->one == -1)
			e = tmp->one + e;
		tmp = tmp->next;
	}
	if (s > 1 || e < -1)
		return (0);
	return (1);
}

void	function_for_normbl(int *res, int *r)
{
	*res = 0;
	*r = 0;
}

int		all_room(t_str *s, t_lem *lem, char *line)
{
	t_str	*start;
	t_str	*tmp;
	int		res;
	int		r;

	function_for_normbl(&res, &r);
	tmp = s;
	start = s;
	while (tmp)
	{
		while (s)
		{
			if (!(ft_strcmp(tmp->str, s->str)) && !r)
				r++;
			else if (!(ft_strcmp(tmp->str, s->str)) && r)
				error_fn(lem, line, s);
			s = s->next;
		}
		r = 0;
		tmp = tmp->next;
		res++;
		s = start;
	}
	s = start;
	return (res);
}
