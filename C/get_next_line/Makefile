# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:41:24 by romannbroque      #+#    #+#              #
#    Updated: 2022/03/15 17:18:09 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

########## SRCS

PATH_SRCS = srcs

SRCS += main.c
SRCS += gnl.c
SRCS += utilities.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

########## INCLUDES

INCLUDES += includes/

HEADER = gnl.h

vpath %.h $(INCLUDES)

########## COMPILER

CC = clang

CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=adress, undefined
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
