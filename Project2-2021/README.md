# Project 2: Bitwise Operations and Debugging Puzzles

## Project Overview

This project is divided into two parts. In the first part, a series of programming problems involving bitwise operations and data representations are solved. In the second part, a GNU Debugger (gdb) is used to reverse engineer a puzzle program and determine the required input values to successfully complete the program.

## Part 1: Bitwise Puzzles

### Description

In the first part of the project, a series of bitwise programming puzzles are solved. These puzzles are used to understand bit-level representations of integers and floating-point numbers. The puzzles require you to use only a limited set of bitwise operators (`!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`) and no constants larger than 8 bits.

### Puzzles Solved

- **minusOne**: Return a value of -1 using bitwise operations.
- **thirdBits**: Return an integer with every third bit set to 1.
- **byteSwap**: Swap two specified bytes within an integer.
- **copyLSB**: Set all bits of the result to the same value as the least significant bit of the input.
- **isPositive**: Return 1 if the input is positive, 0 otherwise.
- **floatNegate**: Return the bit-level equivalent of the expression -f for floating point input f.
- **anyEvenBit**: Return 1 if any even-numbered bit in the input is set to 1.
- **isAsciiDigit**: Return 1 if the input is an ASCII character code for '1' through '9'.
- **floatIsLess**: Compute if floating-point input f is less than g.
- **logicalShift**: Shift the input to the right by a specified amount using a logical shift.
- **greatestBitPos**: Return a mask that marks the location of the most significant 1 bit in the input.
- **floatScale1d2**: Return the bit-level equivalent of the expression 0.5 * f for floating-point value f.

### Tools Used

- **dlc**: A utility to check code for compliance with coding restrictions.
- **btest**: A program to test solutions against a variety of inputs.
- **ishow**: A program to show integer representations.
- **fshow**: A program to show floating-point representations.

## Part 2: Debugging the Puzzlebox

### Description

In the second part of the project, a GNU Debugger (gdb) is used to solve a puzzle program. The puzzle program reads inputs from a file and performs calculations to check if the inputs are correct. The goal is to deduce the correct inputs to pass all phases of the program.

### Steps Taken

1. **Analyze the Puzzlebox Source Code**: Understand how the program processes inputs.
2. **Use gdb to Debug**: Pause execution, inspect variables, and step through code to understand the logic.
3. **Determine Correct Inputs**: Modify the input file based on the insights gained from debugging to successfully pass each phase.

### Tools Used

- **GNU Debugger (gdb)**: A tool to pause program execution, inspect values, and step through code.

### Example Workflow

1. **Start gdb**: `gdb -tui ./puzzlebox`
2. **Set Arguments**: `set args input.txt`
3. **Set Breakpoint**: `break phase01`
4. **Run the Program**: `run`
5. **Inspect Values**: `print variable`
6. **Modify Inputs**: Edit `input.txt`
7. **Re-run the Program**: `run`

## Project Details

This project emphasized:
- Understanding and implementing bitwise operations in C.
- Debugging using gdb to reverse engineer a program.
- Solving programming puzzles that require deep thinking and problem-solving skills.

## Getting Started

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Installation

1. **Clone the repository**:
   ```sh
   git clone (link to project)
   cd (project path)

2. **Compile the program**:
   ```sh
   make

3. **Run the bitwise tests**:
   ```sh
   ./btest

3. **Run the puzzlebox program**:
   ```sh
   ./puzzlebox input.txt
