# ----------------- VARIABLES -----------------
NAME = gnl_test
NAME_BONUS = gnl_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= 1

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# ----------------- RULES -----------------

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) $(CFLAGS) $(OBJ) main.o -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) main.o
	$(CC) $(CFLAGS) $(OBJ_BONUS) main.o -o $(NAME_BONUS)

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

rebonus: fclean bonus

# ----------------- TEST -----------------
test: re
	./$(NAME)

test_bonus: rebonus
	./$(NAME_BONUS)

.PHONY: all clean fclean re test bonus rebonus test_bonus