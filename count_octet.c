/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_octet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:06:30 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/11 16:35:26 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		count_octet(char *str, int cmd)
{
	char **op;
	int		nb_octet;
	int		i;
	int		size;
	int		j;

	size = 0;
	if (!(op = ft_strsplit_asm((const char *)str, &size)))
		exit(0);
	nb_octet = 1;
	if (ft_strcmp(op[cmd - 1], "live") == 0 || ft_strcmp(op[cmd - 1], "zjmp") == 0 || (ft_strcmp(op[cmd - 1], "fork") == 0) || ft_strcmp(op[cmd - 1], "lfork") == 0)
	{
		nb_octet += 0;
	}
	else
		nb_octet += 1;
	i = cmd;
//	while (i < size)
//	{
//		ft_printf("%s\n", op[i]);
//		i++;
//	}
//	i = 1;
	while (i < size)
	{
		j = 0;
		if (op[i][j] == ',')
			j++;
		if (op[i][j] == 'r' && ft_isdigit(op[i][j + 1]))
		{
			nb_octet += 1;
		}
		if (op[i][j] == DIRECT_CHAR)
		{
			if (ft_strcmp(op[cmd - 1], "zjmp") == 0 || ft_strcmp(op[cmd - 1], "ldi") == 0 ||ft_strcmp(op[cmd - 1], "sti") == 0 ||ft_strcmp(op[cmd - 1], "fork") == 0 ||ft_strcmp(op[cmd - 1], "lldi") == 0 ||ft_strcmp(op[cmd - 1], "lfork") == 0)
			{
				nb_octet += 2;
			}
			else if (ft_strcmp(op[cmd - 1], "live") == 0 || ft_strcmp(op[cmd - 1], "ld") == 0 || ft_strcmp(op[cmd - 1], "and") || ft_strcmp(op[cmd - 1], "or") == 0 || ft_strcmp(op[cmd - 1], "xor") == 0 || ft_strcmp(op[cmd -1], "lld") == 0)
			{
				nb_octet += 4;
			}
		}
		if ((op[i][j] == '-' && ft_isdigit(op[i][j + 1])) || ft_isdigit(op[i][j]))
		{
			nb_octet += 2;
		}
		i++;
	}
	free_split(&op, size);
	return (nb_octet);
}
