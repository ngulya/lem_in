/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 17:08:39 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 17:08:40 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

char	*go_to_minus(char *line, int *i)
{
	char	*tmp;

	tmp = line;
	while (*tmp && *tmp != '-')
	{
		tmp++;
		(*i)++;
	}
	return (tmp);
}

int		correct_link(char *line, t_str *s)
{
	t_str	*tmp;
	int		i;
	char	*tmp_line;

	i = 0;
	tmp = s;
	tmp_line = go_to_minus(line, &i);
	if (!*tmp_line || *tmp_line != '-')
		return (0);
	while (tmp && ft_strncmp(line, tmp->str, i))
		tmp = tmp->next;
	tmp_line++;
	if (!tmp || (tmp && !ft_strcmp(tmp->str, tmp_line)))
		return (0);
	tmp = s;
	while (tmp && ft_strcmp(tmp_line, tmp->str))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	return (1);
}
