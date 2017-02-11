/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 18:38:53 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/11 16:32:57 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_header(t_e *e)
{
	int i;
	t_liste *tmp;
	int j;

	i = 0;
	j = 0;
//	e->header.magic[0] = 0;
//	e->header.magic[1] = 0xea;
//	e->header.magic[2] = 0x83;
//	e->header.magic[3] = 0xf3;
//	e->header.magic[4] = 0;
	e->header.magic = (unsigned char*)convert((unsigned int)0xea83f3, 4);
	tmp = e->liste;
	while (tmp)
	{
		if (ft_strstr(tmp->str, NAME_CMD_STRING))
			break ;
		tmp = tmp->next;
	}
	while (tmp->str[i] != '"')
		i++;
	i++;
	while (tmp->str[i + j] != '"')
		j++;
	if (!(e->header.prog_name = (char *)ft_memalloc(sizeof(char) * (PROG_NAME_LENGTH + 1))))
		exit(0);
//	ft_bzero(e->header.prog_name, sizeof(char*));
	e->header.prog_name = ft_strncpy(e->header.prog_name, &tmp->str[i], j);
//ft_printf("progname : %s", e->header.prog_name);
	while (tmp)
	{
		if (ft_strstr(tmp->str, COMMENT_CMD_STRING))
			break ;
		tmp = tmp->next;
	}
	while (tmp->str[i] != '"')
		i++;
	i++;
	while (tmp->str[i + j] != '"')
		j++;
	if (!(e->header.comment = (char *)ft_memalloc(sizeof(char) * (COMMENT_LENGTH + 1))))
		exit(0);
//	ft_bzero(e->header.comment, sizeof(char*));
	e->header.comment = ft_strncpy(e->header.comment, &tmp->str[i], j);
}
