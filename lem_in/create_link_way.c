/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:32:24 by ngulya            #+#    #+#             */
/*   Updated: 2017/05/12 15:32:24 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_rec	*tmp_create_func(t_rec *new, t_rec *tmp, int one, int two)
{
	while (tmp->back && tmp->back->back && tmp->back->back->num != -69)
	{
		if (tmp->num == -13)
		{
			create_answer(new, 0);
			if (tmp->next->num != -69 && tmp->back && \
				tmp->back->back && tmp->back->back->back\
				&& tmp->back->back->back->num != -69)
				func_create_link_from(new, one, two, 1);
		}
		else if (tmp->num == -69)
			;
		else if (tmp->num != -69 && tmp->num != -13)
			create_answer(new, tmp->num);
		tmp = tmp->back;
	}
	return (tmp);
}

void	create_link_way(t_rec *new, t_rec *tmp)
{
	int		one;
	int		two;

	while (tmp)
	{
		if (tmp->back && tmp->back->back && tmp->back->back->num == -69)
		{
			two = tmp->back->num;
			one = tmp->num;
			tmp = tmp->back->back;
			func_create_link_from(new, one, two, 1);
			tmp = tmp_create_func(new, tmp, one, two);
		}
		else if (tmp->num != -69 && tmp->num != -13)
		{
			create_answer(new, tmp->num);
			tmp = tmp->back;
		}
		else
			tmp = tmp->back;
	}
	create_answer(new, 0);
}
