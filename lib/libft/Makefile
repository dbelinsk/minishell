# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 11:53:35 by dbelinsk          #+#    #+#              #
#    Updated: 2020/10/01 14:39:52 by mpernia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
OPT = -I .

SRC = $(shell find . -name 'ft_*.c' | grep -v 'bonus' | rev | cut -d '/' -f1 | rev)
OBJ = $(patsubst %.c,%.o,$(SRC))

B_SRC = $(shell find . -name 'ft_*bonus.c' | rev | cut -d '/' -f1 | rev)
B_OBJ = $(patsubst %.c,%.o,$(B_SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OPT) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(B_OBJ)
	@gcc $(FLAGS) $(OPT) -c $(B_SRC)
	@ar rc $(NAME) $(B_OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ) $(B_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
