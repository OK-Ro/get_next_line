# ----------------- VARIABLES -----------------
NAME = gnl_test

CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= 42

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

# ----------------- RULES -----------------

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) $(CFLAGS) $(OBJ) main.o -o $(NAME)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c main.c

# ----------------- CLEANING -----------------
clean:
	rm -f $(OBJ) main.o

fclean: clean
	rm -f $(NAME)

re: fclean all

# ----------------- TEST -----------------
test: re
	./$(NAME)

.PHONY: all clean fclean re test