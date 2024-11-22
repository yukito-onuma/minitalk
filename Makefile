# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:19:47 by yonuma            #+#    #+#              #
#    Updated: 2024/11/22 16:37:07 by yonuma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = server.c client.c server_bonus.c client_bonus.c
OBJECTS = $(SOURCES:.c=.o)

all: server client server_bonus client_bonus

bonus: server_bonus client_bonus

server: server.o libft/libft.a printf/printf.a
	$(CC) -o $@ $< -Llibft -lft -Lprintf -l:printf.a

client: client.o libft/libft.a printf/printf.a
	$(CC) -o $@ $< -Llibft -lft -Lprintf -l:printf.a

server_bonus: server_bonus.o libft/libft.a printf/printf.a
	$(CC) -o $@ $< -Llibft -lft -Lprintf -l:printf.a

client_bonus: client_bonus.o libft/libft.a printf/printf.a
	$(CC) -o $@ $< -Llibft -lft -Lprintf -l:printf.a

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

libft/libft.a:
	make -C libft

printf/printf.a:
	make -C printf

clean:
	rm -f $(OBJECTS)
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f server client server_bonus client_bonus libft/libft.a printf/printf.a

re: fclean all

.PHONY: all bonus clean fclean re
