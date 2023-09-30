# holbertonschool-monty

The goal of this project is to create an interpreter for Monty ByteCodes files.

## Usage

To use the Monty interpreter, you can follow these steps:

1. Compile the source code using the following command `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`
2. Run the interpreter using the following command:`./monty`
   where `<filename>` is the name of the Monty ByteCode file.

## Files

The following files are included in this project:

- `bytecodes`: a directory containing sample Monty ByteCode files.
- `helper_funcs.c`: a file containing helper functions used by the interpreter.
- `main.c`: the main file of the interpreter.
- `monty`: the compiled executable of the interpreter.
- `monty.h`: a header file containing function prototypes and struct definitions used by the interpreter.
- `opcode.c`: a file containing functions that implement the different Monty ByteCode instructions.

## Examples

Here are some examples of how to use the Monty interpreter:`$ cat bytecodes/00.m push 1 push 2 push 3 pall $ ./monty bytecodes/00.m 3 2 1 $`

## Authors

This project was created by JRMC-PR and GuilleP2018
