/*
  Name: Sudoku solver 
  Author: SuryaK
  Description: Sudoku puzzle solver by brute force algorithm
*/


#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

//global declarations
int sudoku[size][size];
int TempArr[size][size];

int main (void)
{       
    input();
 
    BruteForce();
    printf("\nThe sudoku solution is\n");
    output();
    
    system("pause");
    return 0;

}//main()
