# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/22 15:18:20 by nschilli          #+#    #+#              #
#    Updated: 2015/10/22 16:44:46 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =	serveur

SRCDIR = $(NAME)/srcs/
HDDIR = -I $(NAME)/includes/

CFILES = $(NAME).c \

SRC = $(addprefix $(SRCDIR), $(CFILES))

GCC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -O3 -g

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

%.o: %.c
	@echo -n .
	@$(GCC) $(CFLAGS) -c -o $@ $^ $(HDDIR)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"

re: fclean all

.PHONY: clean fclean re
