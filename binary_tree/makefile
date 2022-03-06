# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 17:12:05 by romannbroque      #+#    #+#              #
#    Updated: 2022/03/06 19:08:50 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = binary_tree

######### SRCS

PATH_SRCS += srcs

SRCS += binary_tree.c
SRCS += create_struct.c
SRCS += route.c
SRCS += display_route.c
SRCS += get_info.c

vpath %.c $(PATH_SRCS)

######### OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

######### INCLUDES

INCLUDES += includes/

HEADER = binary_tree.h

vpath %.h $(INCLUDES)

######### COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

######### RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INCLUDES)
	@echo $(NAME) compiled !

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

.PHONY: all fclean clean re
#.SILENT:
