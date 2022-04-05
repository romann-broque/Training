# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:41:24 by romannbroque      #+#    #+#              #
#    Updated: 2022/04/05 11:38:49 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_lem_in

########## SRCS

PATH_SRCS += srcs
PATH_SRCS += srcs/utilities
PATH_SRCS += srcs/linked_list
PATH_SRCS += srcs/reader
PATH_SRCS += srcs/parser
PATH_SRCS += srcs/room
PATH_SRCS += srcs/error
PATH_SRCS += srcs/path
PATH_SRCS += srcs/graph

SRCS += main.c
SRCS += instructions.c

SRCS += gnl.c
SRCS += line_editor.c

SRCS += parser.c
SRCS += get_arg.c

SRCS += struct_room.c
SRCS += display_room.c

SRCS += display_error.c

SRCS += display.c
SRCS += get_info.c
SRCS += linked_list.c
SRCS += pop.c
SRCS += push.c
SRCS += reverse.c
SRCS += struct.c

SRCS += utilities.c

SRCS += path_finder.c
SRCS += struct_path.c
SRCS += find_shortest_paths.c
SRCS += display_path.c

SRCS += struct_graph.c
SRCS += display_graph.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

########## INCLUDES

INCLUDES += includes/

HEADER += mini_lem_in.h
HEADER += linked_list.h
HEADER += gnl.h
HEADER += utilities.h

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
