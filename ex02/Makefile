# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwagner <mwagner@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 13:59:17 by mwagner           #+#    #+#              #
#    Updated: 2023/06/23 14:15:08 by mwagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VAL 		:= valgrind -s --leak-check=full --show-leak-kinds=all
CAT 		:= | cat > new.log
RUN 		:= ./Account
LOG			:= new.log
AWK 		:= awk 'FNR==NR{a[$$2];next} !($$2 in a)' 19920104_091532.log $(LOG)

GREEN 		:= \033[0;32m
RED 		:= \033[0;31m
RESET_COL 	:= \033[0m

NAME 		:= Account
CC 			:= c++
CFLAGS 		:= -Wall -Werror -Wextra -std=c++98
SRC 		:=	Account.cpp \
				tests.cpp

all: $(NAME)

$(NAME): $(SRC)
	@echo "$(RED)Compiling $(NAME)...$(RESET_COL)"
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GREEN) $(NAME)!$(RESET_COL)"

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME) $(LOG)

re: fclean all

val:
	$(VAL) $(RUN)
cat:
	$(RUN) $(CAT)
awk:
	$(AWK)

.PHONY: all clean fclean re
