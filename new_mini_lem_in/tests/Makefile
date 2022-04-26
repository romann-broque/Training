# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:21:37 by romannbroque      #+#    #+#              #
#    Updated: 2022/04/26 10:09:49 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe

########## SRCS

PATH_SRCS += ../srcs/
PATH_SRCS += ../srcs/parser
PATH_SRCS += ../srcs/parser/gnl
PATH_SRCS += ../srcs/parser/instructions
PATH_SRCS += ../srcs/linked_list
PATH_SRCS += ../srcs/utilities

SRCS += display.c
SRCS += remove.c
SRCS += get_info.c
SRCS += string.c

SRCS += gnl.c

SRCS += instructions.c
SRCS += find_inst.c
SRCS += exe_inst.c

SRCS += struct_list.c
SRCS += display_list.c

SRCS += check.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

########## INCLUDES

INCLUDES += ../includes/
INCLUDES += -I /opt/homebrew/opt/check/include/

HEADER += mini_lem_in.h
HEADER += check.h

LIB += /opt/homebrew/opt/check/lib

vpath %.h $(INCLUDES)

########## COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

LINKS += -lcheck
LINKS += -lm
LINKS += -lpthread

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

########## RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -L $(LIB) $(LINKS) -o $@ -I $(INCLUDES)
	@echo $(NAME) COMPILED !

$(PATH_OBJS):
	mkdir $@

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER) $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY:all clean fclean re
