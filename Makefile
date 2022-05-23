# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 18:04:43 by ssabbaji          #+#    #+#              #
#    Updated: 2022/05/23 13:11:45 by ssabbaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = CC

FLAGS = -Wall -Werror -Wextra

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = main.c f.c additional_tools.c\
			   finding_indexes.c\
			   list_manip.c\
			   sort_more.c\
			   sort_smol.c\
			   stack_calc.c\
			   stack_tools.c\
			   ft_joinargs.c\
			   ft_split.c\
			   parsing_tools.c\
			   push_funcs.c\
			   r_funcs.c\
			   more_r.c\
			   address_funcs.c\
			   swap_funcs.c

SRC_BONUS_LIST = checker.c \
				additional_tools.c\
				 finding_indexes.c\
				 list_manip.c\
				 sort_more.c\
				 sort_smol.c\
				 stack_calc.c\
				 stack_tools.c\
				 ft_joinargs.c\
				 ft_split.c\
				 parsing_tools.c\
				 push_funcs.c\
				 r_funcs.c\
				 more_r.c\
				 address_funcs.c\
				 swap_funcs.c


GREEN			=	"\033[1;32m"
PURPLE			=	"\x1b[35m"
RED				=  "\033[0;31m"

SRC = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

SRC_BONUS = $(addprefix $(SOURCES_DIRECTORY), $(SRC_BONUS_LIST))

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

%.o: %.c ./includes/push_swap.h
	$(CC) $(FLAGS) -o $@ -c $<

all: ${NAME}

${NAME}: ${OBJ}
	$(CC) $(OBJ) -o ${NAME}
	@echo ${PURPLE}"$(NAME): Compiling"

bonus: ${OBJ_BONUS}
	$(CC) $(OBJ_BONUS) -o checker
	@echo ${PURPLE}"checker : Compiling"

clean:
	rm -rf $(OBJ) ${OBJ_BONUS}

fclean: clean
	rm -rf $(NAME) checker
	@echo ${GREEN}"$(NAME) : nadafa mina l iman ..."

re: fclean all