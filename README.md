*This activity has been created as part of the 42 curriculum by ralrawaj*

## Description

The `get_next_line` function reads and returns the contents of a file **line by line**.
It takes a **file descriptor** as a parameter and returns the next line each time it is called.

## Instructions

This project contains the following files:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

The header file contains a macro named `BUFFER_SIZE`.

To compile the project with a custom `BUFFER_SIZE`, use:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c <file_with_main.c>
```

If you do not want to change the `BUFFER_SIZE` (the default value is 50), use:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c <file_with_main.c>
```

After compiling, an executable file named `a.out` will be created.
To run it, use:

```bash
./a.out
```

## Resources

- [File Descriptors Explained](https://youtu.be/KM5sRWAYqaw?si=_fmoQGkOGI1P1Cwt)
- [read() Function Explanation](https://pubs.opengroup.org/onlinepubs/009604599/functions/read.html)

## AI Usage

AI tools were used to:
- Fix syntax and grammar errors in this README file
- found and fix memory leaks in the code
- Help explain the project requirements and expected behavior

## Algorithm

The program works as follows:

1. The function starts by reading data from the file descriptor.
2. Each time new data is read, it is joined with the remaining data stored in the static variable `sub_str`.
3. The combined string is scanned for a newline character (`'\n'`, ASCII value 10).
4. If a newline character is found:
   - The string is split.
   - The part before the newline character is returned as the current line.
5. After returning a line, `sub_str` is updated to store only the remaining text for the next function call.

**Note:**  
The function continues reading until it finds the first newline character or reaches the end of the file.

