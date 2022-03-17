# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:41:24 by romannbroque      #+#    #+#              #
#    Updated: 2022/03/17 23:00:51 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_lem_in

########## SRCS

PATH_SRCS += srcs
PATH_SRCS += srcs/parser
PATH_SRCS += srcs/struct
PATH_SRCS += srcs/reader
PATH_SRCS += srcs/error
PATH_SRCS += srcs/linked_list

SRCS += main.c
SRCS += instructions.c

SRCS += parser.c
SRCS += get_arg.c
SRCS += utilities.c

SRCS += create_struct.c

SRCS += gnl.c
SRCS += reader.c
SRCS += line_editor.c

SRCS += display_error.c

SRCS += display.c
SRCS += get_info.c
SRCS += linked_list.c
SRCS += pop.c
SRCS += push.c
SRCS += reverse.c
SRCS += struct.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

########## INCLUDES

INCLUDES += includes/

HEADER += mini_lem_in.h

vpath %.h $(INCLUDES)

########## COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

########## RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INCLUDES)
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

.PHONY: all clean fclean re
