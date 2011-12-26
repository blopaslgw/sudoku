# include <stdio.h>
# include "lib.h"

extern int sudoku[size][size];

int check (int i, int j, int n)
{
    if (check_row_column(i,j,n) == 1)
    {    
              if (check_box(i,j,n) == 1)
                   return 1;
              else
                  return 0;
    }
    else 
       return 0;
} // check();

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

int check_row_column (int i, int j, int n)
{
    int walk, flag=0;
    for (walk=0; walk<size; walk++)
    {
        flag=0;
        if (sudoku[i][walk]==n || sudoku[walk][j]==n)
           return 0;
        else 
           flag=1;
    }
    if (flag==1)
       return 1;
}
