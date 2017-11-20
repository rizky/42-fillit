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

SRC=	main.c
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
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	# $(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<
	$(CC) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): obj libft $(OBJ) 
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

debug: obj libft $(OBJ) 
	$(CC) $(LIBLINK) -g $(SRCDIR)main.c

remlib:
	rm -rf $(LIBFT)

remoblib:
	make fclean -C ./libft/

clean: remoblib
	rm -rf $(OBJDIR)

fclean: clean remlib
	rm -rf $(NAME)

re: fclean all
