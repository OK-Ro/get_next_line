*This project has been created as part of the 42 curriculum by rokuni.*

## Description

**get_next_line** is a C project that implements a function to read a file line by line. The core challenge is to efficiently read arbitrary-length lines from a file descriptor using a fixed-size buffer, managing memory dynamically, and handling edge cases like missing newlines at EOF.

The project teaches:
- Static variables and state management
- Dynamic memory allocation and deallocation
- File I/O operations
- String manipulation without standard library functions
- Buffer management with configurable sizes

## Instructions

### Compilation

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o gnl
```

The `BUFFER_SIZE` macro controls the read buffer size. Common values: 1, 32, 1024, 4096.

### Execution

```bash
# Create a test file
echo -e "line1\nline2\nlast line" > test.txt

# Run the program
./gnl
```

Output:
```
line1
line2
last line
```

### Memory Leak Check

```bash
valgrind --leak-check=full ./gnl
```

## Algorithm Explanation

### Core Logic

1. **Buffered Reading**: Read `BUFFER_SIZE` bytes at a time into a temporary buffer.
2. **Accumulation**: Use a static `leftover` pointer to accumulate data across function calls.
3. **Line Detection**: Check for `'\n'` in accumulated data.
4. **Splitting**: When a newline is found (or EOF), extract the line and preserve remaining data.
5. **State Preservation**: The static variable maintains state between calls, avoiding re-reading.

### Pseudocode

```
function get_next_line(fd):
    static leftover = NULL
    
    // Step 1: Read until newline found or EOF
    while newline NOT in leftover:
        read BUFFER_SIZE bytes from fd
        if read returns 0 (EOF) or -1 (error): break
        append to leftover
    
    // Step 2: Check if leftover is empty
    if leftover is empty: return NULL
    
    // Step 3: Extract line
    if newline in leftover:
        line = substring from start to newline (inclusive)
        leftover = substring after newline
    else:
        line = duplicate of leftover
        leftover = NULL
    
    return line
```

### Why This Approach?

- **Efficiency**: Reads in chunks rather than byte-by-byte.
- **Flexibility**: `BUFFER_SIZE` can be tuned for performance.
- **Correctness**: Handles files with/without trailing newlines, empty lines, and EOF.
- **State Management**: Static variable avoids global variables and maintains context.

## Project Structure

```
get_next_line/
├── get_next_line.c          # Main function & split_line helper
├── get_next_line_utils.c    # String utility functions
├── get_next_line.h          # Header file with function declarations
├── test.txt                 # Test file
└── README.md                # This file
```

## Functions

### Public
- `char *get_next_line(int fd)` — Reads and returns the next line from file descriptor `fd`.

### Utilities (in get_next_line_utils.c)
- `size_t ft_strlen(const char *s)` — Returns string length.
- `char *ft_strchr(const char *s, int c)` — Finds first occurrence of character.
- `char *ft_strdup(const char *s)` — Duplicates a string.
- `char *ft_strjoin(const char *s1, const char *s2)` — Joins two strings.

### Static Helpers
- `char *split_line(char **leftover)` — Extracts line and updates leftover.
- `char *ft_substr(const char *s, unsigned int start, size_t len)` — Extracts substring.

## Resources

### Documentation
- [man read(2)](https://linux.die.net/man/2/read) — File descriptor reading
- [man malloc(3)](https://linux.die.net/man/3/malloc) — Dynamic memory allocation
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) — State preservation

### Key Concepts
- Buffer management and circular buffers
- Finite State Machines (FSM) for line parsing
- Memory safety and leak prevention

### References
- 42 School Norm: C coding standard
- Valgrind: Memory debugging tool

## AI Usage

**GitHub Copilot** was used for:
1. **Code generation**: Refactoring functions to stay under 25-line limit.
2. **Bug fixes**: Identifying and fixing uninitialized variables and NULL pointer dereferences in `ft_strdup` and `ft_strjoin`.
3. **Function splitting**: Creating `split_line` helper to keep main function concise.
4. **Documentation**: Generating this README structure and algorithm explanation.

## Testing

```bash
# Test 1: Basic functionality
./gnl test.txt

# Test 2: Memory leaks
valgrind --leak-check=full ./gnl

# Test 3: With different BUFFER_SIZE
gcc -D BUFFER_SIZE=1 -o gnl_small get_next_line.c get_next_line_utils.c
gcc -D BUFFER_SIZE=4096 -o gnl_large get_next_line.c get_next_line_utils.c
```

## Notes

- The static `leftover` pointer can only handle **one open file descriptor** at a time due to its static nature. For multiple FDs, use a different architecture (e.g., list of buffers keyed by FD).
- The function returns `NULL` on error or EOF with no remaining data.
- Free all returned lines after use to prevent memory leaks.

---

**Status**: Complete and tested with valgrind ✓