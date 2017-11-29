# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arizzell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 18:51:38 by arizzell          #+#    #+#              #
#    Updated: 2017/11/28 14:00:44 by arizzell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC= main.c init_board.c input_handler.c print_board.c tetrs_decoder.c tetrs_manager.c arrange_tetrs.c
OBJ= $(SRC:.c=.o)

CC= gcc
CFLAGS= -Wall -Wextra -Werror

LIBFT= ./libft/libft.a
LIBINC= -I./libft
LIBLINK= -L./libft -lft
INC= fillit.h

all: $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) $(LIBINC) -I $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@make -C ./libft

$(NAME): libft $(OBJ) 
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

remlib:
	@rm -rf $(LIBFT)

remoblib:
	@make fclean -C ./libft/

clean: remoblib
	@rm -rf $(OBJ)

fclean: clean remlib
	@rm -rf $(NAME)

re: fclean all
