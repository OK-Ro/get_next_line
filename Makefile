# VARIABLES
NAME = gnl
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 32

# DEFAULT RULE
all: $(NAME)

# BUILD EXECUTABLE
$(NAME): $(OBJ)
    $(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $(OBJ) -o $(NAME)
    @echo "✓ Compiled $(NAME) with BUFFER_SIZE=$(BUFFER_SIZE)"

# COMPILE .c -> .o
%.o: %.c get_next_line.h
    $(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

# CLEAN OBJECT FILES
clean:
    rm -f $(OBJ)
    @echo "✓ Cleaned object files"

# REMOVE OBJECT FILES AND EXECUTABLE
fclean: clean
    rm -f $(NAME) gnl_size* test.txt
    @echo "✓ Cleaned all"

# REBUILD EVERYTHING
re: fclean all

# RUN WITH TEST FILE
test: $(NAME)
    @echo "Creating test file..."
    @echo -e "line1\nline2\nlast line no newline" > test.txt
    @echo "Running $(NAME)..."
    @./$(NAME)

# MEMORY LEAK CHECK WITH VALGRIND
leaks: $(NAME)
    @echo "Running valgrind (leak check)..."
    @valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# TEST WITH DIFFERENT BUFFER_SIZE VALUES
test_sizes: fclean
    @echo "Testing with BUFFER_SIZE=1..."
    @$(CC) $(CFLAGS) -D BUFFER_SIZE=1 $(SRC) -o gnl_size1
    @echo -e "line1\nline2\nlast" > test.txt
    @./gnl_size1
    @echo "\nTesting with BUFFER_SIZE=32..."
    @$(CC) $(CFLAGS) -D BUFFER_SIZE=32 $(SRC) -o gnl_size32
    @./gnl_size32
    @echo "\nTesting with BUFFER_SIZE=4096..."
    @$(CC) $(CFLAGS) -D BUFFER_SIZE=4096 $(SRC) -o gnl_size4096
    @./gnl_size4096
    @rm -f gnl_size*
    @echo "✓ All buffer size tests completed"

# HELP TARGET
help:
    @echo "Usage: make [target]"
    @echo ""
    @echo "Targets:"
    @echo "  all        - Compile the project (default)"
    @echo "  clean      - Remove object files"
    @echo "  fclean     - Remove all generated files"
    @echo "  re         - Clean and rebuild"
    @echo "  test       - Run with test file"
    @echo "  leaks      - Run memory leak check with valgrind"
    @echo "  test_sizes - Test with different BUFFER_SIZE values"
    @echo "  help       - Display this help message"

.PHONY: all clean fclean re test leaks test_sizes help