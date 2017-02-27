/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:38:53 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/25 10:08:29 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fin_c(t_liste *tmp, int i, int j, t_e *e)
{
	while (tmp->str[i] != '"')
		i++;
	i++;
	while (tmp->str[i + j] != '"')
		j++;
	if (!(e->header.comment = (char *)ft_memalloc(sizeof(char) * (COMMENT_LENGTH + 1))))
		exit(0);
	e->header.comment = ft_strncpy(e->header.comment, &tmp->str[i], j);
}

void	create_header(t_e *e)
{
	int			i;
	t_liste		*tmp;
	int			j;

	i = 0;
	j = 0;
	if (!(e->header.magic = (unsigned char*)convert((unsigned int)0xea83f3, 4)))
		exit(0);
	tmp = e->liste;
	while (tmp && !(ft_strstr(tmp->str, NAME_CMD_STRING)))
		tmp = tmp->next;
	while (tmp->str[i] != '"')
		i++;
	i++;
	while (tmp->str[i + j] != '"')
		j++;
	if (!(e->header.prog_name = (char *)ft_memalloc(sizeof(char) * (PROG_NAME_LENGTH + 1))))
		exit(0);
	e->header.prog_name = ft_strncpy(e->header.prog_name, &tmp->str[i], j);
	while (tmp && !(ft_strstr(tmp->str, COMMENT_CMD_STRING)))
		tmp = tmp->next;
	j = 0;
	fin_c(tmp, i, j, e);
}
