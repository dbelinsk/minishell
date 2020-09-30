NAME = gnl.a
FLAGS = -Wall -Werror -Wextra
OPT = -I get_next_line.h

SRC = $(shell find . -name '*.c' | rev | cut -d '/' -f1 | rev)
OBJ = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OPT) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ) $(B_OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
