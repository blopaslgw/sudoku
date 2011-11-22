# include <stdio.h>
# include "lib.h"

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
