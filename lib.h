
/*
  Name: lib.h, header file. 
  Copyright: 
  Author: Surya Kasturi
  Date: 31/10/11 23:29
  Description: contains functions required to perform sudoku solver.
*/

#ifndef _lib_H
#define _lib_H
  # define size 9
  # define nmax 10
int BruteForce (void);
int check (int i, int j, int n);
int check_row (int i, int j, int n);
int check_column (int i, int j, int n);
int check_box_9x9 (int i, int j, int n);
int input (void);
int output (void);

#endif //lib.h
