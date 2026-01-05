# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrabh <hrabh@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/04 11:17:03 by hrabh             #+#    #+#              #
#    Updated: 2026/01/04 17:36:37 by hrabh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
HEADER = includes/push_swap.h
SRCS = $(wildcard sources/*.c) main.c

OBJC = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I includes  $< -o $@

clean:
	rm -f $(OBJC)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
