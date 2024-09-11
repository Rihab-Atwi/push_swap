# Push_swap

## Project Overview

*Push_swap* is a project designed to enhance your understanding of sorting algorithms and their complexities. The goal is to sort a stack of integers using the fewest possible operations, employing a predefined set of stack manipulation commands. This project challenges you to develop an optimized sorting algorithm and deepens your understanding of algorithmic efficiency.

## Features

- *Two Stacks*: The project utilizes two stacks, a and b, where stack a initially holds all the integers to be sorted, and stack b starts empty.
- *Operations*: The program supports a set of operations to manipulate the stacks, such as sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, and rrr.
- *Sorting Goal*: The primary objective is to sort stack a in ascending order with the fewest operations.

## Instructions

### Usage

1. *Compilation*: Use the provided Makefile to compile the project. Run the following command:
   
   make
   

2. *Execution*: Execute the program by passing a list of integers as arguments:
   
   ./push_swap [integers...]
   

3. *Output*: The program will output the sequence of operations required to sort the stack.

### Example

sh
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa


## Error Handling

- The program handles errors such as non-integer inputs, duplicates, and integers outside the allowable range.
- In case of an error, the program displays Error followed by a newline.

## Evaluation Criteria

- *Efficiency*: The project will be evaluated based on the number of operations required to sort the stack.
- *Benchmarking*: To validate the project, it should sort 100 random numbers in fewer than 700 operations and 500 random numbers in fewer than 5500 operations.
