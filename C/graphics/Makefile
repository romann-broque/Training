# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 12:57:35 by rbroque           #+#    #+#              #
#    Updated: 2022/08/11 11:04:59 by romannbroque     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = graphics

### SRCS

PATH_SRCS = srcs

SRCS += main.c

vpath %.c $(PATH_SRCS)

### OBJS

PATH_OBJS = objs

OBJS = $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

### INCLUDES

INCLUDES += includes/

HEADER += graphics.h

vpath %.h $(INCLUDES)

### COMPILATION

CC = gcc
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifeq ($(debug), true)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
endif

### RULES

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework Appkit $^ -o $@ -I $(INCLUDES)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ -I $(INCLUDES)

clean:
	$(RM) -R $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
