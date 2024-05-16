# Project 1: Gradebook Program

## Project Overview

This project is a Gradebook Program implemented in C, designed to manage assignment grades for students using a hash table data structure. The program features a command-line interface (CLI) for interacting with the gradebook, allowing users to add new scores, search for existing scores, print all scores, and read/write the assignment scores to/from both binary and text files.

## Features

- **Dynamic Memory Management**: Efficiently manage memory with `malloc()` and `free()`.
- **File I/O**: Read and write gradebook data in both text and binary formats.
- **Command-Line Interface**: User-friendly CLI for interacting with the gradebook.
- **Data Structures**: Utilize C structs to build and manage a hash table for storing grades.

## Commands

The Gradebook Program supports the following commands:

- **create `<name>`**: Creates a new gradebook with the specified class name.
- **class**: Displays the name of the current gradebook.
- **add `<name>` `<score>`**: Adds or updates the score for a student.
- **lookup `<name>`**: Searches for a student's score by name.
- **clear**: Clears the current gradebook.
- **print**: Prints all scores in the gradebook.
- **write_text**: Saves the gradebook to a text file.
- **read_text `<file_name>`**: Loads the gradebook from a text file.
- **write_bin**: Saves the gradebook to a binary file.
- **read_bin `<file_name>`**: Loads the gradebook from a binary file.
- **exit**: Exits the program.

## File Structure

- **Makefile**: Build file to compile code and run test cases.
- **gradebook.h**: Header file for the gradebook data structure.
- **gradebook.c**: Implementation of gradebook functions.
- **gradebook_main.c**: Command-line interface implementation.
- **tests**: Directory containing test cases and test scripts.

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

3. **Run the program**:
   ```sh
   ./gradebook_main

## Automated Testing

This project includes automated tests to verify the functionality of the program. To run the tests use the folowing command:
```sh
make test

