# ----------------- VARIABLES -----------------
NAME = gnl_test
NAME_BONUS = gnl_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= 42

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# ----------------- RULES -----------------

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) $(CFLAGS) $(OBJ) main.o -o $(NAME)

bonus: $(OBJ_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c main.c

# ----------------- CLEANING -----------------
clean:
	rm -f $(OBJ) $(OBJ_BONUS) main.o

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

# ----------------- TEST -----------------
test: re
	./$(NAME)

.PHONY: all clean fclean re test bonus