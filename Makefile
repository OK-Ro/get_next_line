
# ----------------- VARIABLES -----------------
NAME = get_next_line
BONUS_NAME = get_next_line_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE ?= 42

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# ----------------- RULES -----------------

all: $(NAME)

# Mandatory
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

# Bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

# ----------------- CLEANING -----------------
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) main.c -o gnl_test
	./gnl_test

.PHONY: all bonus clean fclean re test
	
