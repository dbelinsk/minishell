NAME=minishell
GNL=./lib/gnl/gnl.a
LIBFT=./lib/libft/libft.a
COMP_FLAG=-Wall -Wextra -Werror

SRC_PATH=./srcs/
OBJ_PATH=./obj/
LIB_PATH=./lib/
INC_PATH=./include/ $(LIB_PATH)libft/  $(LIB_PATH)gnl/

SRC_NAME=$(shell find $(SRC_PATH) -name "*.c" | rev | cut -d '/' -f1 | rev)
OBJ_NAME=$(patsubst %.c, %.o, $(SRC_NAME))
LIB_NAME= libft gnl

SRCS=$(shell find $(SRC_PATH) -name "*.c")
OBJS=$(patsubst %.c, %.o, $(SRCS))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC=$(addprefix -I, $(INC_PATH))
LIBS=$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB=$(addprefix -L, $(LIBS))

all: $(NAME)

$(NAME): $(OBJS)
	@printf "libft..."
	@make -C $(LIB_PATH)libft > /dev/null 2>&1
	@printf "done\ngnl..."
	@make -C $(LIB_PATH)gnl > /dev/null 2>&1
	@printf "done\nminishell..."
	@gcc $(COMP_FLAG) $(INC) $(LIB) $(OBJ) -lft -lgnl -o $(NAME)
	@gcc $(INC) $(LIB) $(OBJ) -lft -lgnl -o $(NAME)
	@echo done

soft:
	@gcc $(COMP_FLAG) $(INC) $(LIB) $(OBJ) -lft -lgnl -o $(NAME)

%.o: %.c
	@mkdir -p $(OBJ_PATH)
	#@gcc $(COMP_FLAG) $(INC) -o $@ -c $<
	@gcc $(INC) -o $@ -c $<
	@mv $@ $(OBJ_PATH)

clean:
	@rm -fv $(OBJ) > /dev/null 2>&1
	@rm -rf $(OBJ_PATH) > /dev/null 2>&1

fclean: clean
	@make -C $(LIB_PATH)libft fclean
	@make -C $(LIB_PATH)gnl fclean
	@rm -fv $(NAME) > /dev/null 2>&1

re: fclean all
