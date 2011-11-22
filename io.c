# include <stdio.h>
# include <string.h>
# include "lib.h"

extern int sudoku[size][size];
extern int TempArr[size][size];

int input (void)
{    
    int i, j;
    char str[100];
    FILE* ip_file;
    
    printf("Welcome to Sudoku Solver.\n");
    printf("- There are still some major bugs to be resolved. sorry!\n\n");
    
    printf("Rules to follow before entering input\n");
    printf("       1. Enter 0 in place of empty location\n");
    printf("       2. Enter the file name with extension & address\n");
	printf("       Ex: F:\folder1\foo1\input.txt \n\n\n");
    
    //Take file location as input
    printf("File: ");
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
                      TempArr[i][j]=sudoku[i][j];
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

int output(void)
{
    int i, j;
    
    printf("\n");
    printf("    0 1 2  3 4 5  6 7 8\n");
    for (i = 0; i < 9; i++) 
    {
        if (i%3 == 0)
             printf("  + - - -+ - - -+ - - - +\n");
        for (j = 0; j < 9; j++) 
        {
            if (j==0)
              printf("%d |",i);
            if (j%3 == 0 && j!=0)
                printf("|");
            printf(" %d",sudoku[i][j]);
        }
        printf(" |\n");
    }
    printf("  + - - -+ - - -+ - - - +\n\n");
}
