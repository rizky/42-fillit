.PHONY: all clean re clean proper

CC := gcc
# CFLAGS := -Wall -Werror -Wextra
CFLAGS : =
NAME := fillit
SRC := main.c
OBJ := main.o
HEADERS = -I includes/
LIBLINK= -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBLINK) $^ $(HEADERS)

%.o : src/%.c
	$(CC) $(CFLAGS) -c $< $(HEADERS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

debug:
	@gcc -g src/*.c $(HEADERS)