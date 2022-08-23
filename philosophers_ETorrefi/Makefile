# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etorrefi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 13:51:47 by etorrefi          #+#    #+#              #
#    Updated: 2022/07/01 13:51:48 by etorrefi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

src = main.c InitParam.c utils.c

obj = $(src:.c=.o)

hd = philo.h

flags = -Wall -Wextra -Werror

cc = gcc

all: $(NAME)

$(NAME): $(src) $(obj) $(hd)
	$(cc) $(flags) $(src) -o $(NAME)

%.o : %.c
	$(cc) $(flags) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(NAME)

re: fclean all
