/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_name_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 16:19:16 by ngulya            #+#    #+#             */
/*   Updated: 2017/06/04 16:19:16 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	write_out_b(int num, char *s)
{
	ft_putchar('L');
	ft_putnbr(num);
	ft_putchar('-');
	ft_putstr(s);
	ft_putchar(' ');
}

int		koord(char *tmp)
{
	while (*tmp != ' ')
	{
		if (*tmp >= '0' && *tmp <= '9')
			tmp++;
		else
			return (0);
	}
	tmp++;
	if (!*tmp)
		return (0);
	while (*tmp)
	{
		if (*tmp >= '0' && *tmp <= '9')
			tmp++;
		else
			return (0);
	}
	return (1);
}

int		size_name_room(char *line, t_str *s, t_lem *lem)
{
	char	*tmp;
	int		i;

	if (!*line)
		error_fn(lem, line, s);
	if (*line == '#')
		return (1);
	i = 0;
	tmp = line;
	while (*tmp && *tmp != ' ')
	{
		tmp++;
		i++;
	}
	if (*tmp == ' ')
	{
		if (koord(++tmp))
			return (i);
		else
			error_fn(lem, line, s);
	}
	return (0);
}
