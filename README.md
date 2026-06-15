# C Expression Evaluator (Reverse Polish Notation)

A command-line application written in C that parses mathematical expressions, converts them into postfix notation (Reverse Polish Notation), and evaluates the final result using variable assignments.

# Features
* Infix to Postfix Conversion: Implements the classic Shunting-yard algorithm to handle operator precedence and parentheses correctly.
* Custom Stack Implementation: Uses array-based stacks for both characters (operators/variables) and integers.
* Variable Matching: Dynamically maps character variables (`a`, `b`, `c`, etc.) to integer values loaded from an external input file.

# Technical Overview
* Language: C (C99 Standard)
* Core Concepts: Stacks (LIFO), Pointers, File I/O, Memory Operations, String Parsing.
* Supported Operators: `+`, `-`, `*`, `/`, `^` (power), along with bracket precedence `()`.

# Input File Format (`file.txt`)
The program reads the mathematical equation from a text file where the first line represents the formula and the second line lists the integer values for each unique variable in alphabetical order.

*Example `file.txt`:

a^(b-c)+d/(e+f*g)-h
2 3 3 30 6 4 1 6
