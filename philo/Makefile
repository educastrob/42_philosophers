# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 04:35:57 by educastro         #+#    #+#              #
#    Updated: 2024/10/28 19:18:18 by edcastro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
CFLAGS := -Wextra -Wall -Werror
CFLAGS += -g3 -O3 -pthread
JOBS := -j50
CC := cc
RM := rm -rf

OBJ_DIR := build
INCLUDE_DIR := includes
INCLUDES := -I$(INCLUDE_DIR)

SRCS := sources/philosophers.c \
		sources/init.c \
		sources/utils.c \
		sources/exit.c \
		sources/main.c
SRCS += sources/lib/ft_isspace.c \
        sources/lib/ft_atoi.c \
        sources/lib/ft_isdigit.c \
        sources/lib/ft_memset.c
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

print_start:
	@echo "Compiling $(NAME)...$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): print_start $(OBJS)
	@$(CC) $(OBJS) $(INCLUDES) $(CFLAGS) -o $(NAME)
	@echo "$(NAME) COMPILED!$(RESET)"

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all print_start clean fclean re