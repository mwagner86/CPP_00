VAL =		valgrind -s --leak-check=full --show-leak-kinds=all
RUN =		./megaphone

GREEN = \033[0;32m
RED = \033[0;31m
RESET_COL = \033[0m

NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC =	megaphone.cpp

all: $(NAME)

$(NAME): $(SRC)
	@echo "$(RED)Compiling $(NAME)...$(RESET_COL)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN) $(NAME)!$(RESET_COL)"

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

val:
	$(VAL) $(RUN)

.PHONY: all clean fclean re