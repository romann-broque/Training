# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:16:51 by romannbroque      #+#    #+#              #
#    Updated: 2022/03/11 14:33:44 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = binary

########## SRCS

PATH_SRCS += srcs

SRCS += main.c
SRCS += print_binary.c
SRCS += endian_toggle.c
SRCS += display.c
SRCS += calcul.c

vpath %.c $(PATH_SRCS)

########## OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

########## INCLUDES

INCLUDES += includes/

HEADER = binary.h

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
