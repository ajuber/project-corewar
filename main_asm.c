/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 13:07:35 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/25 09:27:17 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char **argv)
{
	t_e			e;
	int			i;
	t_liste		*tmp;
	char		*pl;

	ft_bzero(&e, sizeof(t_e));
	e.fd = open(argv[argc - 1], O_RDONLY);
	if (e.fd == -1)
	{
		ft_printf("Can't read file %s\n", argv[argc - 1]);
		return (0);
	}
	if (!ft_strstr(argv[argc - 1], ".s"))
	{
		ft_printf("Lexical error at [1:1]\n");
		return (0);
	}
	recup_file(&e);
	i = 0;
	while (argv[argc - 1][i] != '.')
		i++;
	if (!(e.str = ft_strsub(argv[argc - 1], 0, i)))
		return (0);
	e.str = ft_strjoin_free(e.str, e.str, ".cor");
	e.fd1 = open("plop.cor", O_CREAT | O_RDWR | O_APPEND | O_TRUNC, 0640);
	if (e.fd1 == -1)
	{
		ft_printf("Error to create file\n");
		return (0);
	}
	init_liste_op(&e);
	e.nb_instruct = count_nb_instruct(e.liste, &e);
	if (!(e.tab = (t_op_ft *)malloc(sizeof(t_op_ft) * e.nb_instruct)))
		return (0);
	i = 0;
	tmp = e.liste;
	while (i < e.nb_instruct)
	{
		while (op_or_ft(tmp->str, &e) == 0)
		{
			tmp = tmp->next;
		}
		if (op_or_ft(tmp->str, &e) == 2)
		{
			pl = first_word(tmp->str);
			if (!(e.tab[i].ft = ft_strsub(pl, 0, ft_strlen(pl) - 1)))
				exit(0);
		//	ft_printf("tab dans main 2  %s\n", e.tab[i].ft);
			e.tab[i].cmd = 2;
			e.tab[i].nb_octet = count_octet(tmp->str, e.tab[i].cmd);
		//	ft_printf("%d\n", e.tab[i].nb_octet);
			e.header.prog_size += e.tab[i].nb_octet;
			if (!(e.tab[i].str = ft_strdup(tmp->str)))
				exit(0);
			free_line(&pl);
		}
		else if (op_or_ft(tmp->str, &e) == 3)
		{
			e.tab[i].nb_octet = 0;
			pl = first_word(tmp->str);
		//	ft_printf("pl : %s\n", pl);
			if (!(e.tab[i].ft = ft_strsub(pl, 0, ft_strlen(pl) - 1)))
				exit(0);
		//	ft_printf("tab dans main  %s\n", e.tab[i].ft);
			e.tab[i].cmd = 3;
			e.tab[i].nb_octet = 0;
			if (!(e.tab[i].str = ft_strdup(tmp->str)))
				exit(0);
			free_line(&pl);
		}
		else
		{
			e.tab[i].cmd = 1;
			e.tab[i].nb_octet = count_octet(tmp->str, e.tab[i].cmd);
		//	ft_printf("%d\n", e.tab[i].nb_octet);
			e.header.prog_size += e.tab[i].nb_octet;
			if (!(e.tab[i].str = ft_strdup(tmp->str)))
				exit(0);
		}
		i++;
		tmp = tmp->next;
	}
	create_header(&e);
	i = 0;
	while (i < 4)
	{
		ft_printf_fd(e.fd1, "%c", e.header.magic[i]);
		i++;
	}
	ft_putstr_size_fd(e.fd1, e.header.prog_name, PROG_NAME_LENGTH);
	if (!(e.header.size = (unsigned char*)convert(e.header.prog_size, 8)))
		exit(0);
	i = 0;
	while (i < 8)
	{
		ft_printf_fd(e.fd1, "%c", e.header.size[i]);
		i++;
	}
	ft_putstr_size_fd(e.fd1, e.header.comment, COMMENT_LENGTH);
	i = 0;
	while (i < 4)
	{
		ft_printf_fd(e.fd1, "%c", 0);
		i++;
	}
	print_prog(&e);
	ft_free_all(&e);
//	while (1)
//	{}
	return (0);
}
