# include <stdio.h>
# include <string.h>
# include "lib.h"

extern int sudoku[size][size];
extern int TempArr[size][size];

int input (void)
{    
    int i, j;
    char* str[100];
    FILE* ip_file;
    
    printf("Welcome to Sudoku Solver.\n");
    printf("   # Author: SuryaK\n");
    printf("   # Project Description: Sudoku puzzle solver using\n");
    printf("                          Brute Force Algorithm\n\n");
    printf("- There are still some major bugs to be resolved. sorry!\n\n");
    
    printf("Rules to follow before entering input\n");
    printf("       1. Enter 0 in place of empty location\n");
    printf("       2. Enter the file name with extension & address\n\n");
    
    //Take file location as input
    printf("Enter the file name along with location\n");
    scanf("%s",str);
    
    ip_file = fopen(str,"r+");
    if (ip_file == NULL) 
    {
                perror ("couldn't open input file.\n");
                system("pause");
    }
    
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            if(fscanf(ip_file,"%d",&sudoku[i][j])==1)
            {         
                      //copy to TempArr
                      TempArr[i][j]==sudoku[i][j];
            }
            else
            {
                perror ("fscanf failed on input file.\n");
                // return error
            }
        }
    }
    printf("Thanks for entering. Your Sudoku is...\n");
         output();

            
}// input()

int output (void)
{  
   int i,j;
   int val=0;
   
   printf("\n");   
   for (i=0;i<size;i++)
   {   
       for (j=0;j<size;j++)
       {  
          val++;
          printf("%d ",sudoku[i][j]);
       }
       printf("\n");
         if (val==27)
         { 
           val=0;
           printf("-----+-----+-----\n"); 
         }
   }
   printf("       **       \n");
   
} //output();
