# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:19:47 by yonuma            #+#    #+#              #
#    Updated: 2024/05/25 13:47:42 by yonuma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk.a
SRCS = server.c \
	   client.c \
	   client_bonus.c \
	   server_bonus.c
	   
# BONUS = 
	   
OBJS = $(SRCS:.c=.o)
OBJS_B = $(BONUS:.c=.o)
# INCLUDES = -I includes

all : $(NAME)

# bonus : 
# 	@make all "OBJS = $(OBJS) $(OBJS_B)"

$(NAME) : $(OBJS) $(OBJS_B)
	ar rc $@ $^

%.o:%.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean : 
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all
.PHONY : all clean fclean re