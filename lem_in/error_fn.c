/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:13:50 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 15:13:51 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	special_for_t_str_in_error(t_str *str)
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
	ft_putstr("Error\n");
	exit(1);
}

void	error_fn(t_lem *l, char *line, t_str *str)
{
	t_str	*s;
	int		i;

	i = 0;
	if (line && *line)
		free(line);
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
	special_for_t_str_in_error(str);
}
