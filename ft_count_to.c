/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:48:44 by ajubert           #+#    #+#             */
/*   Updated: 2017/01/23 16:55:10 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_count_to(t_e *e, int i, char *str)
{
	int res;
	int j;

	res = 0;
	j = 0;
	while (i + j < e->nb_instruct)
	{
		res += e->tab[i + j].nb_octet;
		if (e->tab[i + j].cmd == 3 && ft_strstr(e->tab[i + j].ft, str))
			return (res);
		j++;
	}
	res = 0;
	j = 0;
	while (i - j >= 0)
	{
		res -= e->tab[i - j].nb_octet;
		if (e->tab[i - j].cmd == 3 && ft_strstr(e->tab[i - j].ft, str))
			return (res);
		j--;
	}
	return (0);
}
