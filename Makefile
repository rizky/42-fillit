# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arizzell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 18:51:38 by arizzell          #+#    #+#              #
#    Updated: 2017/11/19 18:51:39 by arizzell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC= main.c \
	init_board.c \
	input_handler.c \
	print_board.c \
	tetrs_decoder.c \
	tetrs_manager.c \
	arrange_tetrs.c

OBJ= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC= gcc
CFLAGS= -Wall -Wextra -Werror

LIBFT= ./libft/libft.a
LIBINC= -I./libft
LIBLINK= -L./libft -lft

SRCDIR= ./src/
INCDIR= ./includes/
OBJDIR= ./obj/

all: $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@make -C ./libft

$(NAME): obj libft $(OBJ) 
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

debug: obj libft $(OBJ) 
	@$(CC) $(LIBLINK) -g $(SRCDIR)*.c

remlib:
	@rm -rf $(LIBFT)

remoblib:
	@make fclean -C ./libft/

clean: remoblib
	@rm -rf $(OBJDIR)

fclean: clean remlib
	@rm -rf $(NAME)

re: fclean all

test: re
	./fillit tests/ok_tetrs0 | cat -e
	./fillit tests/ok_tetrs1 | cat -e
	./fillit tests/ok_tetrs2 | cat -e
	./fillit tests/ok_tetrs3 | cat -e
	./fillit tests/bad_tetrs0 | cat -e
	./fillit tests/bad_tetrs1 | cat -e
	./fillit tests/bad_tetrs2 | cat -e
	./fillit tests/bad_tetrs3 | cat -e
	./fillit tests/bad_tetrs4 | cat -e
	./fillit tests/bad_tetrs3 tests/bad_tetrs3 | cat -e
	./fillit | cat -e

run-debug: debug
	lldb a.out

run: re
#	./fillit tests/correct_file/valid_9
	./fillit tests/correct_file/valid_13
