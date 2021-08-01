# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/29 13:10:57 by xuwang            #+#    #+#              #
#    Updated: 2021/08/01 19:48:54 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGE = -Wall -Wextra -Werror
SRC := srcs/main.c \
		srcs/utils.c \
		srcs/init.c \
		srcs/philo.c 

OBJ := $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGE) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGE) $(OBJ) -I. -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re