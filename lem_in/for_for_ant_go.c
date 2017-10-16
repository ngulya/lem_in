/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_for_ant_go.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:20:00 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/05 19:20:00 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_var	*sec_i_s(t_var *al)
{
	if (al->num != -1)
	{
		al->next = (t_var *)malloc(sizeof(t_var));
		al = al->next;
		al->num_ways = 0;
		al->num_room = 0;
		al->next = NULL;
	}
	return (al);
}

void	for_free_not_good(t_var *al, t_var **tmp)
{
	if (al)
	{
		*tmp = al->next;
		al->next = NULL;
	}
}
