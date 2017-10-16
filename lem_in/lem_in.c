/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:00:12 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 18:00:12 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	valid_ant(t_lem *lem, t_str *str)
{
	char	*line;
	char	*tmp;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!line || *line != '#')
			break ;
		else if (!(ft_strcmp("##end", line)) || !ft_strcmp("##start", line))
			error_fn(lem, line, str);
		create_map(lem, line);
		free(line);
	}
	tmp = line;
	if (line && *line && !max_int(line))
	{
		lem->ant = ft_atoi(line);
		create_map(lem, line);
		free(line);
	}
	else
		error_fn(lem, line, str);
}

void	for_v_room(int *one, int *i)
{
	*i = -1;
	*one = 0;
}

void	valid_room(t_lem *lem, t_str *s)
{
	char	*line;
	t_str	*tmp;
	int		one;
	int		i;

	tmp = s;
	for_v_room(&one, &i);
	line = NULL;
	while (get_next_line(0, &line) && size_name_room(line, s, lem))
	{
		line = start_end(line, &one, lem, s);
		if (*line != '#')
		{
			if (!(i = size_name_room(line, s, lem)))
				error_fn(lem, line, s);
			write_str(&s, &one, line, i);
		}
		create_map(lem, line);
		free(line);
	}
	s = tmp;
	if (i == -1 || !one_start_one_end(s) || !correct_link(line, tmp)\
		|| all_room(s, lem, line) <= 1 || lem->ant <= 0)
		error_fn(lem, line, s);
	matrix_func(s, lem, line, all_room(s, lem, line));
}

int		main(void)
{
	t_lem	*lem;
	t_str	*str;

	lem = (t_lem *)malloc(sizeof(t_lem));
	str = (t_str *)malloc(sizeof(t_str));
	str->one = -69;
	str->next = NULL;
	str->str = NULL;
	lem->map = NULL;
	lem->mas = NULL;
	valid_ant(lem, str);
	valid_room(lem, str);
}
