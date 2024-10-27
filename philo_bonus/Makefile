# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 15:56:59 by educastro         #+#    #+#              #
#    Updated: 2024/10/27 17:23:51 by edcastro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo_bonus
CFLAGS := -Wextra -Wall -Werror
CFLAGS += -g3 -O3 -pthread
JOBS := -j50
CC := cc
RM := rm -rf

OBJ_DIR := build
INCLUDE_DIR_BONUS := includes
INCLUDES := -I$(INCLUDE_DIR_BONUS)

SRCS_BONUS := sources/utils_bonus.c \
				sources/exit_bonus.c \
				sources/main_bonus.c \
				sources/philosophers_bonus.c \
				sources/init_bonus.c
SRCS_BONUS += sources/lib/ft_memset_bonus.c \
				sources/lib/ft_isdigit_bonus.c \
				sources/lib/ft_atoi_bonus.c \
				sources/lib/ft_isspace_bonus.c
OBJS_BONUS := $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

all: $(NAME)

print_start:
	@echo "Compiling $(NAME)...$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): print_start $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(INCLUDES) $(CFLAGS) -o $(NAME)
	@echo "$(NAME) COMPILED!$(RESET)"

bonus:

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all print_start clean fclean bonus re