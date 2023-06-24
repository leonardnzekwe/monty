# C - MONTY

An interpreter for Monty ByteCodes Files.

ALX SWE Project on Stacks, Queues & LIFO, FIFO.

## Authors

- [@leonardnzekwe](https://www.github.com/leonardnzekwe)
- [@rahma-cloud](https://www.github.com/rahma-cloud)

## Features

- Read File line by line.
- Evalute the line opcodes.
- Print the Evaluted opcodes to Output.
- Implements a Doubly Linked List Stack & Queue.
- Implements the LIFO & FIFO.

The monty program

- Usage: monty file

## Task Roadmap

- [x]  **Task 0:** Implement the push and pall opcodes.
- [x]  **Task 1:** Implement the pint opcode.
- [x]  **Task 2:** Implement the pop opcode.
- [x]  **Task 3:** Implement the swap opcode.
- [x]  **Task 4:** Implement the add opcode.
- [x]  **Task 5:** Implement the nop opcode.
- [x]  **Task 6:** Implement the sub opcode.
- [x]  **Task 7:** Implement the div opcode.
- [x]  **Task 8:** Implement the mul opcode.
- [x]  **Task 9:** Implement the mod opcode.
- [x]  **Task 10:** Implement commment line observance.
- [x]  **Task 11:** Implement the pchar opcode.
- [x]  **Task 12:** Implement the pstr opcode.
- [x]  **Task 13:** Implement the rotl opcode.
- [x]  **Task 14:** Implement the rotr opcode.
- [ ]  **Task 15:** Implement the stack and queue opcodes.
- [x]  **Task 16:** Write a Brainf*ck script that prints School, followed by a new line.
- [x]  **Task 17:** Write a Brainf*ck script that adds two digits given by the user
- [ ]  **Task 18:** Write a Brainf*ck script that multiplies two digits given by the user.
- [ ]  **Task 19:** Write a Brainf*ck script that multiplies two double digits given by the user.

## Files

- **monty.h:** contains the header files and prototypes of the monty program
- **aid_funcs.c:** contains all the auxiliary functions of the monty program namely, `get_num_nodes`, `is_valid_number`, `trim_white_space`, `free_stack` and `clean_up`.
- **arith_funcs.c:** contains all the arithmetic function of the monty program namely, `add_func`, `sub_funcs`, `mul_funcs`, `div_func` and `mod_func`.
- **get_line.c:** contains all the monty program function for processing the file lines and opcodes, namely `get_line`, `stack_push` and `search_opcode`.
- **main.c:** contains all the `main` function where the file handling logic it handled.
- **more_aid_funcs.c:** contains more custom auxiliary functions of the monty program namely, `push_end_func` and `pop_end_func`.
- **opcode_funcs.c:** contains the function that implement the monty program opcodes, namely `push_func`, `pall_funcs`, `pint_func`, `pop_func` and `swap_func`.
- **more_opcode_funcs.c:** contains the more function that implement the monty program opcodes, namely `pchar_func`, `pstr_func`, `rotl_func` and `rotr_func`.

## Directories

- **bytecodes:** contains the monty byte code files for testing.
- **bf:** contains the Brainf*ck script files for that task 16, 17, 18 and 19.

## Limitations

- The program just skips line with the `stack` and `queue` opcodes, without processing it.
