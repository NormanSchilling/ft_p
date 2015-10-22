# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/22 15:18:20 by nschilli          #+#    #+#              #
#    Updated: 2015/10/22 15:20:37 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.sources

export	CC		=	gcc

export	INC		=	-I $(PWD)/libft

SERVEUR		=	serveur
CLIENT		=	client

CFLAGS		=	-Wall -Wextra -Werror -g

INC			+=	-I $(SERVEUR)/includes -I $(CLIENT_INC_SRC)/includes

INC_DIR		=	includes/
SRC_DIR		=	srcs/

#SERVEUR
SERVEUR_INC_FILES	=	$(SERVEUR).h

SERVEUR_INC_SRC		=	$(addprefix $(SERVEUR)/$(INC_DIR), $(SERVEUR_INC_FILES))

SERVEUR_FILES		=	$(SERVEUR).c \

SERVEUR_SRC			=	$(addprefix $(SERVEUR)/$(SRC_DIR), $(SERVEUR_FILES))

SERVEUR_OBJ			=	$(SERVEUR_SRC:.c=.o)

#CLIENT
CLIENT_INC_FILES	=	$(CLIENT).h

CLIENT_INC_SRC		=	$(addprefix $(CLIENT)/$(INC_DIR), $(CLIENT_INC_FILES))

CLIENT_FILES		=	$(CLIENT).c \

CLIENT_SRC			=	$(addprefix $(CLIENT)/$(SRC_DIR), $(CLIENT_FILES))

CLIENT_OBJ			=	$(CLIENT_SRC:.c=.o)

#LIBFT
OBJ_LIB		=	$(libft/SRC_LIB:.c=.o)

HEAD_LIB	=	libft/libft.h

LIB			=	-L./ -lft

all:			libft.a $(SERVEUR) $(CLIENT)

libft.a:		libft/$(OBJ_LIB) $(HEAD_LIB)
	@make -C libft

$(SERVEUR):		$(SERVEUR_OBJ)
	@$(CC) $(CFLAGS) -o $(SERVEUR) $(SERVEUR_OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"Compilation of $(SERVEUR) : "\033[32m"Success"\033[0m"

$(CLIENT):		$(CLIENT_OBJ)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIB)
	@echo ""
	@echo "\033[33m"Compilation of $(CLIENT) : "\033[32m"Success"\033[0m"

%.o:			%.c
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean-serveur:
	@/bin/rm -f $(SERVEUR_OBJ)
	@echo "\033[31m"Objects of $(SERVEUR) : deleted"\033[0m"

clean-client:
	@/bin/rm -f $(CLIENT_OBJ)
	@echo "\033[31m"Objects of $(CLIENT) : deleted"\033[0m"

clean: clean-serveur clean-client

fclean:			clean
	@/bin/rm -f $(CLIENT) $(SERVEUR)
	@echo "\033[31m"$(CLIENT) and $(SERVEUR) : deleted"\033[0m"
	@make fclean -C libft

re:				fclean all

norm:			$(SERVEUR_SRC) $(CLIENT_SRC) $(CLIENT_INC_SRC) $(SERVEUR_INC_SRC)
	@echo "\033[31mNORME server and client\033[0m":
	@norminette $^
	@make norm -C libft

.PHONY:			all clean fclean re clean-serveur clean-client
