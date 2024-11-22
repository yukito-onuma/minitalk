# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonuma <yonuma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:19:47 by yonuma            #+#    #+#              #
#    Updated: 2024/11/22 16:19:12 by yonuma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = printf.a
SRCS = ft_printf.c \
	   ft_utils.c \
	   print_unsigned_int.c \
	   return_chr.c \
	   return_int.c \
	   return_percent.c \
	   return_pointer.c \
	   return_str.c \
	   return_ten.c \
	   return_base.c 
	   
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
