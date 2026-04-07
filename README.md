# Get Next Line

*This project has been created as part of the 42 curriculum by rokuni.*

## Description

This project implements the `get_next_line` function, which reads a line from a file descriptor. The function returns one line at a time from the file descriptor, handling buffering efficiently using static variables. It's designed to work with any file descriptor, including standard input, and manages memory properly to avoid leaks.

The goal is to create a reusable function that simplifies reading lines from files or streams, teaching concepts like static variables, buffer management, and dynamic memory allocation in C.

## Instructions

### Compilation

Compile the source files with the required flags and define `BUFFER_SIZE` (default 42 if not specified):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

To test with different buffer sizes (e.g., 1, 1024, or 10000000):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c -o gnl_test
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

### Execution

Run the test program:

```bash
./gnl_test
```

The test reads from `test.txt` and prints each line.

## Algorithm Explanation

The `get_next_line` function uses a static variable to store leftover data between calls, allowing it to handle partial reads efficiently. The algorithm works as follows:

1. **Buffering Loop**: Read data in chunks of `BUFFER_SIZE` into a buffer until a newline is found or EOF is reached. Each chunk is joined to the static `leftover` string.

2. **Line Extraction**: Once a newline is detected in `leftover`, extract the line (including the newline) and update `leftover` to contain only the remaining data.

3. **Edge Cases**: Handle cases where the file doesn't end with a newline, read errors, or empty files. Memory is freed appropriately to prevent leaks.

This approach minimizes reads by stopping as soon as a newline is found, rather than reading the entire file at once. The use of a static variable ensures state persistence across function calls for the same file descriptor.

## Resources

- [42 Get Next Line Subject](https://cdn.intra.42.fr/pdf/pdf/118977/en.subject.pdf) - Official project description
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/) - Explanation of static variables
- [File Descriptors in Unix](https://www.gnu.org/software/libc/manual/html_node/File-Descriptors.html) - Understanding file descriptors

