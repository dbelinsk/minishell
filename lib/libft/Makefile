# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpernia- <mpernia-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 11:53:35 by dbelinsk          #+#    #+#              #
#    Updated: 2020/10/04 17:06:50 by mpernia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	libft.a

CC			= 	gcc
FLAGS		= 	-c -Wall -Wextra -Werror

LIB			= 	ar rc
RLIB		= 	ranlib

PRINTF_DIR	=	./ft_printf/
PRINTF_SRCS =	$(shell find $(PRINTF_DIR) -name "*.c" | rev |	   \
				cut -d '/' -f1 | rev)

SRCS		=	$(shell find . -maxdepth 1 -name "*.c" | rev | cut -d '/' -f1 |\
				rev)

OBJS_DIR	=	./objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(shell find $(OBJS_DIR)\
				-name "*.o" | rev | cut -d '/' -f1 | rev))
OBJECTS		=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS) $(PRINTF_SRCS))

all: $(NAME)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -I. -c $< -o $@

$(OBJS_DIR)%.o: $(PRINTF_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(FLAGS) -I$(PRINTF_DIR) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "Creating objects.."
	@$(LIB) $(NAME) $(OBJS)
	@echo "Creating libft.a"
	@$(RLIB) $(NAME)
	@echo "Complete."

.PHONY: all clean fclean

clean:
	@echo "Cleaning libft objects..."
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Cleaning libft.a"
	@rm -f $(NAME)

re: fclean all

