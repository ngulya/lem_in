/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:26:59 by ngulya            #+#    #+#             */
/*   Updated: 2016/12/07 16:22:05 by ngulya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	**res_w;
	size_t	len;
	int		i;

	i = 0;
	if (!s || !c)
		return (NULL);
	len = ft_perebor(s, c);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (res)
	{
		res[len] = NULL;
		res_w = res;
		while (len > 0)
		{
			res[i] = ft_strdosym(s, c);
			s = ft_pozs(s, ft_strdosym(s, c), c);
			len--;
			i++;
		}
		return (res_w);
	}
	return (NULL);
}
