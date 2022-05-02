# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:41:24 by romannbroque      #+#    #+#              #
#    Updated: 2022/05/02 23:51:40 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_lem_in

########## SRCS

PATH_SRCS += srcs
PATH_SRCS += srcs/parser
PATH_SRCS += srcs/parser/instructions
PATH_SRCS += srcs/linked_list
PATH_SRCS += srcs/reader
PATH_SRCS += srcs/reader/gnl
PATH_SRCS += srcs/struct
PATH_SRCS += srcs/struct/graph
PATH_SRCS += srcs/struct/path
PATH_SRCS += srcs/struct/room
PATH_SRCS += srcs/utilities

SRCS += main.c
SRCS += instructions.c

### linked_list

SRCS += create.c
SRCS += destroy.c
SRCS += display_list.c
SRCS += get_info_list.c

### gnl

SRCS += read_file.c
SRCS += gnl.c

### instructions

SRCS += exe_inst.c
SRCS += find_inst.c

### graph

SRCS += create_graph.c
SRCS += display_graph.c
SRCS += destroy_graph.c
SRCS += get_info_graph.c

### path

SRCS += struct_path.c
SRCS += path_finder.c
SRCS += display_path_list.c

### room

SRCS += create_room.c
SRCS += get_info_room.c
SRCS += destroy_room.c
SRCS += display_room.c

### utilities

SRCS += display.c
SRCS += remove.c
SRCS += get_info.c
SRCS += edit.c
SRCS += compare.c
SRCS += copy.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

########## INCLUDES

INCLUDES += includes/

CHECK_FOLDER += tests/

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

test: $(NAME)
	$(MAKE) -C $(CHECK_FOLDER)
	@echo 
	@echo \\\\\\\\\\\\\\\\\\\\ TESTS //////////
	@echo 
	./$(CHECK_FOLDER)/run_tests.sh ./$(CHECK_FOLDER)/exe

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -C $(CHECK_FOLDER) $@

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(CHECK_FOLDER) $@

re: fclean
	$(MAKE)

.PHONY: all clean fclean re test
