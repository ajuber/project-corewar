/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:38:53 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/28 15:53:37 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_comment(t_liste *tmp, int i, int j, t_e *e)
{
	while (tmp && !(ft_strstr(tmp->str, COMMENT_CMD_STRING)))
		tmp = tmp->next;
	while (tmp->str[i] != '"')
		i++;
	i++;
	while (tmp->str[i + j] != '"')
		j++;
	if (!(e->header.comment = (char *)ft_memalloc(sizeof(char) *
					(COMMENT_LENGTH + 1))))
		exit(0);
	e->header.comment = ft_strncpy(e->header.comment, &tmp->str[i], j);
}

void	create_name(t_liste *tmp, int i, int j, t_e *e)
{
	while (tmp && !(ft_strstr(tmp->str, NAME_CMD_STRING)))
		tmp = tmp->next;
	while (tmp->str[i] != '"')
		i++;
	i++;
	while (tmp->str[i + j] != '"')
		j++;
	if (!(e->header.prog_name = (char *)ft_memalloc(sizeof(char) *
					(PROG_NAME_LENGTH + 1))))
		exit(0);
	e->header.prog_name = ft_strncpy(e->header.prog_name, &tmp->str[i], j);
}

int		order(t_liste *tmp)
{
	while (tmp)
	{
		if (ft_strstr(tmp->str, NAME_CMD_STRING))
			return (1);
		if (ft_strstr(tmp->str, COMMENT_CMD_STRING))
			return (2);
		tmp = tmp->next;
	}
	return (0);
}

void	create_header(t_e *e)
{
	int			i;
	t_liste		*tmp;
	int			j;
	int			ord;

	i = 0;
	j = 0;
	if (!(e->header.magic = (unsigned char*)convert((unsigned int)0xea83f3, 4)))
		exit(0);
	tmp = e->liste;
	ord = order(tmp);
	if (ord == 1)
	{
		create_name(tmp, i, j, e);
		i = 0;
		j = 0;
		create_comment(tmp, i, j, e);
	}
	if (ord == 2)
	{
		create_comment(tmp, i, j, e);
		i = 0;
		j = 0;
		create_name(tmp, i, j, e);
	}
}
