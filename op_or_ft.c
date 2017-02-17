/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:54:24 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/17 16:20:29 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*first_word(char *str)
{
	int i;
	int j;
	char *tmp;

	j = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
		i++;
	}
	while (str[i + j] && (!ft_strchr(" \t", str[i + j])))
	{
		j++;
	}
	if (j == 0)
		return (NULL);
	if (!(tmp = ft_strsub(str, i, j)))
		exit(0);
	return (tmp);
}

char	*second_word(char *str)
{
	int i;
	int j;
	char *tmp;

	j = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i + j] && (!ft_strchr(" \t", str[i + j])))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i + j] && (!ft_strchr(" \t", str[i + j])))
		j++;
	if (j == 0)
		return (NULL);
	if (!(tmp = ft_strsub(str, i, j)))
		exit(0);
	return (tmp);
}

int		op_or_ft(char *str, t_e *e)
{
	char *word;
	int i;
	int op;
	char *word2;

	op = 0;
//	ft_printf("----------dans op_or_ft-----------\n");
	word = first_word(str);
	word2 = second_word(str);
//	ft_printf("%s\n",word);
	if (word == NULL)
		return (0);
	i = 0;
	if (ft_strchr(word, ':'))
		op = 3;
	while (i < NB_OP)
	{
		if (op == 0 && ft_strcmp(word, e->liste_op[i]) == 0)
		{
			free_line(&word);
			return (1);
		}
		if (op == 3 && word2 && ft_strcmp(e->liste_op[i], word2) == 0)
		{
			free_line(&word);
			return (2);
		}
		i++;
	}
	if (op == 3)
	{
			free_line(&word);
		return (3);
	}
			free_line(&word);
	return (0);
}
