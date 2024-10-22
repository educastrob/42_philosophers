# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 04:35:57 by educastro         #+#    #+#              #
#    Updated: 2024/10/22 18:45:30 by edcastro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c init.c exit.c

MAINPATH = $(addprefix ./sources/, $(SRC))

FLAGS = -Wall -Wextra -Werror -O3 -pthread

HEADER = ./includes/philosophers.h

SANITIZER = -fsanitize=thread

all: $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@cc $(FLAGS) -o $(NAME) $(MAINPATH) $(SANITIZER)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
