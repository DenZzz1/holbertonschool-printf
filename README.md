# Printf

This project consists of recreating a simplified version of the standard C function `printf`.

---

## Project Objectives

- Implement a `_printf` function capable of printing formatted text.
- Organize a C project properly using multiple source files.
- Follow the Betty coding style guidelines.

---

## Supported Features

The `_printf` function must handle the following format specifiers:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string of characters |
| `%%` | Prints the `%` character |
| `%d` | Prints a signed integer in base 10 |
| `%i` | Prints a signed integer in base 10 |

---

## Project Files

### `_printf.c`
- Core of the program.
- Iterates through the format string.
- Detects format specifiers.
- Calls the corresponding handling functions.
- Manages output and counts printed characters.

### `print_int.c`
- Handles `%d` and `%i` format specifiers.
- Converts signed integers to characters using an internal conversion function.
- Correctly handles negative integers without relying on the standard `printf`.

### `main.h`
- Contains all required function prototypes.
- Declares helper functions and internal structures.
- Protected with an include guard.

end
