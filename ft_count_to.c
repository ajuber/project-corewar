/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:48:44 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/25 09:35:37 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_count_to(t_e *e, int i, char *str1)
{
	int res;
	int j;
	char *str;

	if (str1[ft_strlen(str1) - 1] == ',')
	{
		if (!(str = ft_strsub(str1, 2, ft_strlen(&str1[2]) - 1)))
			exit(0);
	}
	else
		if (!(str = ft_strsub(str1, 2, ft_strlen(&str1[2]))))
			exit(0);
	if (str[0])
	{
	}
	res = 0;
	j = 0;
	while (i + j < e->nb_instruct)
	{
		res += e->tab[i + j].nb_octet;
//		if (e->tab[i + j].cmd == 3 || e->tab[i+ j].cmd == 2)
//			ft_printf("tab : %s           str : %s\n", e->tab[i + j].ft, str);
		if ((e->tab[i + j].cmd == 3 || e->tab[i+ j].cmd == 2) && ft_strcmp(str, e->tab[i + j].ft) == 0)
			return (res);
		j++;
	}
	res = 0;
	j = 0;
	while (i - j >= 0)
	{
		if (j == 0)
			res += e->tab[i - j].nb_octet;
		res -= e->tab[i - j].nb_octet;
//		if (e->tab[i - j].cmd == 3 || e->tab[i- j].cmd == 2)
//			ft_printf("%s      %s\n", e->tab[i - j].ft, str);
		if ((e->tab[i - j].cmd == 3 || e->tab[i- j].cmd == 2) && ft_strcmp(e->tab[i - j].ft, str) == 0)
			return (res);
		j++;
	}
	return (0);
}
