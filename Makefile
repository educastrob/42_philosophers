# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: educastro <educastro@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 04:35:57 by educastro         #+#    #+#              #
#    Updated: 2024/06/22 14:01:46 by educastro        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c actions.c

MANPATH = $(addprefix ./sources/, $(SRC))

FLAGS = -Wall -Wextra -Werror -O3 -pthread

HEADER = ./includes/philo.h

# SANITIZER = -fsanitize=thread

all: $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@cc $(FLAGS) -o $(NAME) $(MANPATH) $(SANITIZER)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug