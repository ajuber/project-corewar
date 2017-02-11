/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 13:31:02 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/20 16:38:16 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		recup_file(t_e *e)
{
	while (get_next_line(e->fd, &e->line) > 0)
	{
		if (!(e->liste = push_back_l(e->liste, e->line)))
			exit (0);
		free_line(&e->line);
	}
		free_line(&e->line);
	return (0);
}
