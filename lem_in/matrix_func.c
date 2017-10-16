/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:18:22 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 17:18:22 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	first_start_second_end(t_str *s, t_lem *l, char *line)
{
	t_str	*tmp;
	char	*swap;

	tmp = s;
	while (tmp && tmp->one != 1)
		tmp = tmp->next;
	if (!tmp)
		error_fn(l, line, s);
	swap = s->str;
	s->str = tmp->str;
	tmp->str = swap;
	tmp = s->next;
	while (tmp && tmp->one != -1)
		tmp = tmp->next;
	if (!tmp)
		error_fn(l, line, s);
	swap = s->next->str;
	s->next->str = tmp->str;
	tmp->str = swap;
}

int		func_find_minus(char *line)
{
	char	*tmp;
	int		minus;

	tmp = line;
	minus = 0;
	while (*line && *line != '-')
	{
		minus++;
		line++;
	}
	return (minus);
}

int		dop_function_write(t_str *s, t_lem *l, char *line)
{
	int		i;
	int		j;
	char	*start_line;
	t_str	*tmp;

	i = 0;
	j = 0;
	if (*line == '#')
		return (1);
	tmp = s;
	start_line = line;
	if (!correct_link(line, tmp))
		return (0);
	i = dop_dop_function_write(tmp, line, func_find_minus(line));
	tmp = s;
	while (*line != '-')
		line++;
	line++;
	j = dop_dop_function_write(tmp, line, func_find_minus(line));
	line = start_line;
	l->mas[i][j] = 1;
	l->mas[j][i] = 1;
	return (1);
}

void	null_all_mas(t_lem *l)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < l->rooms)
	{
		while (j < l->rooms)
			l->mas[i][j++] = 0;
		j = 0;
		i++;
	}
}

void	matrix_func(t_str *s, t_lem *l, char *line, int rooms)
{
	int		i;

	i = 0;
	l->rooms = rooms;
	first_start_second_end(s, l, line);
	l->mas = (int **)malloc(sizeof(int *) * rooms);
	while (i < rooms)
		l->mas[i++] = (int *)malloc(sizeof(int) * rooms);
	null_all_mas(l);
	if (!dop_function_write(s, l, line))
		error_fn(l, line, s);
	create_map(l, line);
	free(line);
	while (get_next_line(0, &line))
	{
		if (!*line || (*line && (!ft_strcmp("##end", line) ||\
			(!ft_strcmp("##start", line)))) || !dop_function_write(s, l, line))
			error_fn(l, line, s);
		create_map(l, line);
		free(line);
	}
	ants_go_go_go(find_all_way(s, l), l, s);
}
