# include <stdio.h>
# include "lib.h"

extern int sudoku[size][size];

int check_row(int i, int j, int n)
{
   int walki;
   int flag1;

   for (walki=0;walki<size;walki++)
   {  
        flag1 = 0; 
        if (sudoku[walki][j]==n)
        {   
            return 0; 
        }
        
        else 
        {  
            flag1 = 1;
        }
   }
   
   if (flag1==1)
      return 1; 
} //check_row()

int check_column(int i, int j, int n)
{
   int walkj;
   int flag1;
   
   for (walkj=0;walkj<size;walkj++)
   {     
        flag1 = 0; 
        if (sudoku[i][walkj]==n)
        {
            return 0;
        }
        
        else 
        {
            flag1 = 1;
        }
   }
   
   if (flag1==1)
      return 1;
} //check_column()
 
