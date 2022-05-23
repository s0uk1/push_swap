# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssabbaji <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 18:04:43 by ssabbaji          #+#    #+#              #
#    Updated: 2022/05/21 19:19:44 by ssabbaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIRECTORY)

HEADERS_LIST = push_swap.h\

HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = main.c\
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

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

OBJ_BONUS = ${SRC_BONUS:.c=.o}

GREEN			:=	"\033[1;32m"
PURPLE			:=	"\x1b[35m"
RED				:=  "\033[0;31m"

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo ${PURPLE}"$(NAME): Compiling"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo ${GREEN}"$(NAME) : nadafa mina l iman ..."