/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_dop_function_write.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:12:29 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 18:12:30 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		dop_dop_function_write(t_str *tmp, char *line, int minus)
{
	int		i;

	i = 0;
	while (tmp && ft_strncmp(tmp->str, line, minus))
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
