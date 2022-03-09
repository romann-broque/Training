# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romannbroque <rbroque@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 10:48:35 by romannbroque      #+#    #+#              #
#    Updated: 2022/03/08 11:55:13 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_eight_queens

######### SRCS

PATH_SRCS += srcs

SRCS += ft_eight_queens.c
SRCS += display.c
SRCS += get_info.c
SRCS += init.c
SRCS += is_valid.c
SRCS += back_tracking.c
SRCS += pos.c

vpath %.c $(PATH_SRCS)

######### OBJS

PATH_OBJS += objs
OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

######### INCLUDES

INCLUDES += includes/

HEADER = ft_eight_queens.h

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

.PHONY: all clean fclean re
