/*
  Name: lib.h, header file. 
  Copyright: 
  Author: Surya K
  Date: 31/10/11 23:29
  Description: contains functions required to perform sudoku solver.
*/

#ifndef _lib_H
#define _lib_H
  # define size 9
  # define nmax 10
int BruteForce (void);
int check (int i, int j, int n);
int check_row_column(int i, int j, int n);
int check_box (int i, int j, int n);
int input (void);
int output (void);

#endif //lib.h
