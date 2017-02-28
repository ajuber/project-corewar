/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yo_ne_se_pa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:41:22 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/28 15:46:12 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned char	*ft_dir(t_ijkl s, t_e *e, t_sepa z, unsigned char *print, int *k, int l)
{
	int		nb;
	char	*nb_c;
	int		m;

	nb = 0;
	if (s.str[s.i][l] == '-' || ft_isdigit(s.str[s.i][l]))
		nb = ft_atoi(&s.str[s.i][l]);
	else if (ft_isalpha(s.str[s.i][l + 1]))
		nb = ft_count_to(e, s.l, s.str[s.i]);
	m = 0;
	if (!(nb_c = convert((unsigned int)nb, z.dir_sepa)))
		exit(0);
	while (m < z.dir_sepa)
	{
		print[*k] = nb_c[m];
		m++;
		k[0]++;
	}
	free_line(&nb_c);
	return (print);
}

unsigned char	*ft_ind(t_ijkl s, int l, t_sepa z, int *k, unsigned char *print)
{
	int		nb;
	char	*nb_c;
	int		m;

	nb = ft_atoi(&s.str[s.i][l]);
	if (!(nb_c = convert((unsigned int)nb, z.ind_sepa)))
		exit(0);
	m = 0;
	while (m < z.ind_sepa)
	{
		print[*k] = nb_c[m];
		m++;
		k[0]++;
	}
	free_line(&nb_c);
	return (print);
}

unsigned char	*ft_reg(t_ijkl s, int l, unsigned char *print, int *k)
{
	int nb;
	char *nb_c;

	nb = ft_atoi(&s.str[s.i][l + 1]);
	if (!(nb_c = convert((unsigned int)nb, 1)))
		exit(0);
	print[*k] = nb_c[0];
	k[0]++;
	free_line(&nb_c);
	return (print);
}

unsigned char	*ft_yo_ne_se_pa(t_e *e, unsigned char *print, int *k, t_ijkl s)
{
	t_sepa		z;
	int			l;

	l = 0;
	if (ft_strcmp(s.str[s.j], "live") == 0 || ft_strcmp(s.str[s.j], "ld") == 0
			|| ft_strcmp(s.str[s.j], "and") == 0
			|| ft_strcmp(s.str[s.j], "or") == 0
			|| ft_strcmp(s.str[s.j], "xor") == 0
			|| ft_strcmp(s.str[s.j], "lld") == 0)
		z.dir_sepa = 4;
	else
		z.dir_sepa = 2;
	z.ind_sepa = 2;
	if (s.str[s.i][l] == ',')
		l++;
	if (s.str[s.i][l] == '%')
	{
		l++;
		print = ft_dir(s, e, z, print, k, l);
	}
	else if (s.str[s.i][l] == '-' || ft_isdigit(s.str[s.i][l]))
		print = ft_ind(s, l, z, k, print);
	else if (s.str[s.i][l] == 'r')
		print = ft_reg(s, l, print, k);
	return (print);
}
