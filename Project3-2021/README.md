# Project 3: Assembly Programming and Debugging

## Overview

In Project 3, we delve deeper into the intricacies of low-level programming by transitioning from high-level C programming to assembly language. This project is designed to enhance understanding of how software operates at the machine level and involves both assembly coding and reverse engineering a binary using gdb.

## Objectives

1. **Bitwise Operations in Assembly**: Implement solutions to bitwise puzzle problems previously tackled in Project 2, now using x86 assembly language.
2. **Reverse Engineering**: Reverse engineer a binary puzzle program using gdb, without access to its source code, to deduce required input values.

## Project Structure

### Part 1: Bitwise Puzzles in Assembly

Implemented assembly solutions for bitwise manipulation problems (similar to project 2), focusing on the translation of logical operations into assembly instructions.

#### Key Files:
- `bitwise/bits.s`: Assembly implementations for bitwise operations.
- `bitwise/btest.c`: Test harness for evaluating bitwise functions.

### Part 2: Binary Bomb

Debugged and reverse engineered a binary executable to understand its behavior and solve the embedded puzzles without source code access.

#### Key Files:
- `bomb/bomb`: The binary to be reverse engineered.
- `bomb/input.txt`: Custom inputs to the binary, crafted to defuse the bomb.

## Tools and Utilities

- **GNU Debugger (gdb)**: Essential for stepping through assembly code, inspecting state, and verifying logic.
- **Makefiles**: Facilitate building and testing of assembly code and managing complex project builds.

## Achievements

- Developed proficiency in writing and debugging low-level assembly code.
- Enhanced understanding of machine architecture and instruction sets.
- Successfully reverse-engineered binary code to solve complex puzzles.
- Applied methodical and analytical skills in a challenging coding environment.

## Getting Started

To run and test the implementations, follow these steps:

1. **Clone the repository**:
   ```bash
   git clone (link to project)
   cd (path to project)

2. **Compile and test the assembly puzzles**:
   ```bash
   cd bitwise
   make
   ./btest

3. **Go through Bomb in gdb**:
   ```bash
   cd ../bomb
   gdb ./bomb

