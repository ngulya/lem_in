/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 15:06:12 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 15:06:13 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		for_mas_rec(t_rec *ans, int j, int *i, t_lem *l)
{
	*i = 1;
	if (j >= 0 && l->mas[1][j])
	{
		func_create_link_from(ans, -69, j, -13);
		create_answer(ans, j);
		return (1);
	}
	return (0);
}

void	create_map(t_lem *lem, char *line)
{
	t_str	*tmp;

	if (lem->map)
	{
		tmp = lem->map;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = (t_str *)malloc(sizeof(t_str));
		tmp = tmp->next;
		tmp->next = NULL;
		tmp->str = ft_strdup(line);
	}
	else
	{
		lem->map = (t_str *)malloc(sizeof(t_str));
		lem->map->next = NULL;
		lem->map->str = ft_strdup(line);
	}
}
