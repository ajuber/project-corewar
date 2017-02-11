/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:40:52 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/11 17:43:59 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		test_opcode(char *str)
{
	if (ft_strcmp(str, "live") == 0 || ft_strcmp(str, "zjmp") == 0 || ft_strcmp(str, "fork") == 0 || ft_strcmp(str, "lfork") == 0)
		return (0);
	return (1);
}

unsigned char *ft_yo_ne_se_pa(/*t_e *e,*/ unsigned char *print, int *k, char **str, int i, int j, int n)
{
	int dir_sepa;
	int ind_sepa;
	int l;
	int m;
	int nb;
	char *nb_c;

	l = 0;
	if (ft_strcmp(str[j], "live") == 0 || ft_strcmp(str[j], "ld") == 0 || ft_strcmp(str[j], "and") == 0 || ft_strcmp(str[j], "or") == 0 || ft_strcmp(str[j], "xor") == 0 || ft_strcmp(str[j], "lld") == 0)
		dir_sepa = 4;
	else
		dir_sepa = 2;
	ind_sepa = 2;
	if (str[i][l] == ',')
		l++;
	if (str[i][l] == '%')
	{
		l++;
		nb = 0;
		if (str[i][l] == '-' || ft_isdigit(str[i][l]))
			nb = ft_atoi(&str[i][l]);
		else if (ft_isalpha(str[i][l + 1]))
		{
		//	ft_printf("%d    %s", i, str[i]);
		//	nb = ft_count_to(e, n, str[i]);
			nb = n-n;
		}
		m = 0;
		nb_c = convert((unsigned int)nb, dir_sepa);
		while (m < dir_sepa)
		{
			print[*k] = nb_c[m];
			m++;
			k[0]++;
		}
	}
	else if (str[i][l] == '-' || ft_isdigit(str[i][l]))
	{
		nb = ft_atoi(&str[i][l]);
		nb_c = convert((unsigned int)nb, ind_sepa);
		m = 0;
		while (m < ind_sepa)
		{
			print[*k] = nb_c[m];
			m++;
			k[0]++;
		}
	}
	else if (str[i][l] == 'r')
	{
		nb = ft_atoi(&str[i][l + 1]);
		nb_c = convert((unsigned int)nb, 1);
		print[*k] = nb_c[0];
		k[0]++;
	}
	free_line(&nb_c);
	return (print);
}

void	print_prog(t_e *e)
{
	int j;
	int i;
	int k;
	int l;
	char **str;
	int size_str;
	unsigned char *print;
	unsigned char **tmp;

	l = 0;
	while (l < e->nb_instruct)
	{
		while (l < e->nb_instruct && e->tab[l].cmd == 3)
			l++;
		print = malloc(sizeof(unsigned char) * e->tab[l].nb_octet);
	//	ft_printf("\n%s", e->tab[l].str);
		str = ft_strsplit_asm(e->tab[l].str, &size_str);
		if (e->tab[l].cmd == 1)
			j = 0;
		else
			j = 1;
		k = 0;
		print[k] = search_code(str[j], e);
//		k++;
		i = j + 1;
		if (test_opcode(str[j]))
		{
			k++;
			print[k] = opcode(str, i, size_str);
		}
		while (i < size_str)
		{
			k++;
			print = ft_yo_ne_se_pa(/*e,*/ print, &k, str, i, j, l);
			k--;
			i++;
		}
		k = 0;
		while (k < e->tab[l].nb_octet)
		{
			ft_printf_fd(e->fd1, "%c", print[k]);
			k++;
		}
		tmp = &print;
//	ft_printf("ojkoh1\n");
		free_line((char **)tmp);
//	ft_printf("ojkoh2\n");
		free_split(&str, size_str);
//	ft_printf("ojkoh3\n");
		l++;
	}
}
