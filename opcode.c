/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:06:17 by ajubert           #+#    #+#             */
/*   Updated: 2017/01/31 16:43:16 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	opcode(char **str, int i, int size_str)
{
	int		bin[8];
	unsigned char res;
	int j;
	int k;

	res = 0;
	k = 0;
	while (k < 8)
	{
		bin[k] = 0;
		k++;
	}
	k = 0;
	while (i < size_str)
	{
		j = 0;
		if (str[i][j] == ',')
			j++;
		if (str[i][j] == 'r' && ft_isdigit(str[i][j + 1]) == 1)
		{
			bin[k] = 0;
			bin[++k] = 1;
			k++;
		}
		if (str[i][j] == DIRECT_CHAR)
		{
	/*		if (ft_strcmp(str[0], "live") == 0 || ft_strcmp(str[0], "ld") == 0 || ft_strcmp(str[0], "and") || ft_strcmp(str[0], "or") == 0 || ft_strcmp(str[0], "xor") == 0 || ft_strcmp(str[0], "lld") == 0)
				nb_octet += 4;
			else
				nb_octet += 2;*/
			bin[k] = 1;
			bin[++k] = 0;
			k++;
		}
		if ((str[i][j] == '-' && ft_isdigit(str[i][j + 1])) || ft_isdigit(str[i][j]))
		{
			bin[k] = 1;
			bin[++k] = 1;
			k++;
		}
		i++;
	}
	k = 0;
	while (k < 8)
	{
		res = res * 2 + bin[k];
		k++;
	}
	return (res);
}
