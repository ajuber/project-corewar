# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajubert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 14:28:27 by ajubert           #+#    #+#              #
#    Updated: 2017/03/02 15:24:02 by ajubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		asm
COMPILER=	gcc
FLAG=		-g -Wall -Werror -Wextra
LIB=		libft.a
INCLUDES=	-I ./libft/includes/
vpath %.c

SRC_C=	main_asm.c\
		free_line.c\
		list1.c\
		recup_file.c\
		count_nb_instruct.c\
		count_octet.c\
		create_header.c\
		op_or_ft.c\
		init_liste_op.c\
		ft_strsplit_asm.c\
		convert.c\
		print_prog.c\
		ft_count_to.c\
		opcode.c\
		search_code.c\
		ft_free_all.c\
		free_split.c\
		free_tab.c\
		free_liste_op.c\
		ft_yo_ne_se_pa.c\
		create_tab.c

SRC_O=		$(SRC_C:.c=.o)

all: libft.h libft.a $(NAME)

$(NAME): $(SRC_O)
	$(COMPILER) -o $(NAME) $(SRC_O) $(LIB) $(FLAG)
	@echo "\033[32m=======ASM HAS BEEN CREATED=======\033[0m"

%.o: %.c
	$(COMPILER) $(FLAG) -c $(subst __,/,$<) -o $@

libft.a:
	@echo "\033[32m==================================="
	@echo "==========COMPILING LIBFT=========="
	@echo "===================================\033[0m"
	make re -C ./libft/
	cp ./libft/libft.a .
	make fclean -C ./libft/

libft.h:
	cp ./libft/libft/libft.h .
	cp ./libft/libft/get_next_line.h .
	cp ./libft/printf/ft_printf.h .

clean:
	@echo "\033[33m==========REMOVING OBJ FILES==========\033[0m"
	rm -rf $(SRC_O)

fclean: clean
	@echo "\033[31m==========REMOVING BIN FILES==========\033[0m"
	rm -rf $(NAME) libft.a
	rm -rf libft.h
	rm -rf get_next_line.h
	rm -rf ft_printf.h

re: fclean all
