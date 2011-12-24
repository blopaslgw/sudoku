# include <stdio.h>
# include "lib.h"

extern int sudoku[size][size];

int check (int i, int j, int n)
{
    if (check_row(i,j,n) == 1)
    {   
         if (check_column(i,j,n) == 1)
         {     
              if (check_box(i,j,n) == 1)
              {  
                   return 1;
              }
              else
                  return 0;
         }
         else 
            return 0;
    }
    
    else 
       return 0;
} // check();

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
 
int check_box (int i, int j, int n)
{
    int iwalk, jwalk, flag=0;    
   
    for (iwalk = (i/3)*3; iwalk < (i/3)*3 + 3; iwalk++)
    {
        for (jwalk = (j/3)*3; jwalk < (j/3)*3 + 3; jwalk++)
        {
            if ( !(iwalk==i && jwalk == j) )                    
            {   
                flag = 0;         
                if (sudoku[iwalk][jwalk]==n)  
                    return 0; 
                else 
                    flag = 1;              
            }
        }
    }
    if (flag==1)  
       return 1; 
    
} //check_box()
