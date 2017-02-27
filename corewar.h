/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 13:12:36 by ajubert           #+#    #+#             */
/*   Updated: 2017/02/27 17:13:55 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

#define malloc(x) 0
# define NB_OP 16

typedef struct			s_liste
{
	char				*str;
	struct s_liste		*next;
}						t_liste;

typedef struct			s_op_ft
{
	int					nb_octet;
	int					cmd;
	char				*ft;
	char				*str;
}						t_op_ft;

typedef struct			s_ijkl
{
	int					i;
	int					j;
	int					l;
	char				**str;
}						t_ijkl;

typedef struct			s_jk
{
	int					j;
	int					k;
}						t_jk;

typedef struct			s_sepa
{
	int					dir_sepa;
	int					ind_sepa;
}						t_sepa;

typedef struct			s_e
{
	char				*line;
	int					fd;
	int					fd1;
	t_liste				*liste;
	char				*str;
	header_t			header;
	int					nb_instruct;
	t_op_ft				*tab;
	char				**liste_op;
	char				*print;
	int					op;
	int					i;
}						t_e;

void					free_line(char **line);
int						recup_file(t_e *e);
t_liste					*push_back_l(t_liste *begin_list, char *str);
void					create_header(t_e *e);
int						count_nb_instruct(t_liste *liste, t_e *e);
int						op_or_ft(char *str, t_e *e);
char					*first_word(char *str);
int						count_octet(t_e *e, char *str, int cmd);
void					init_liste_op(t_e *e);
char					**ft_strsplit_asm(char const *s, int *size);
char					*convert(int n, int size);
unsigned char			search_code(char *str, t_e *e);
void					print_prog(t_e *e);
unsigned char			opcode(char **str, int i, int size_str);
int						ft_count_to(t_e *e, int i, char *str);
void					ft_free_all(t_e *e);
void					free_split(char ***str, int size);
void					free_tab(t_op_ft **tab, int size);
void					ft_free_list_l(t_liste **begin_list);
void					free_liste_op(char ***tab);
unsigned char			*ft_yo_ne_se_pa(t_e *e, unsigned char *print,
		int *k, t_ijkl s);

#endif
