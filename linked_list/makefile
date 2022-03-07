# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 19:40:39 by romannbroque      #+#    #+#              #
#    Updated: 2022/03/07 00:11:07 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = linked_list

######### SRCS

PATH_SRCS += srcs

SRCS += display.c
SRCS += get_info.c
SRCS += linked_list.c
SRCS += pop.c
SRCS += push.c
SRCS += reverse.c
SRCS += struct.c

vpath %.c $(PATH_SRCS)

######### OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

######### INCLUDES

INCLUDES += includes/

HEADER = linked_list.h

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
