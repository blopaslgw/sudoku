# include <stdio.h>
# include "lib.h"

extern int sudoku[size][size];
int check_box_9x9 (int i, int j, int n)
{    
   
    int loci, locj;
    int i0, i1, j0, j1;
    int flag1;
    
    //box1
    if (i>=0 && i<=2 && j>=0 && j<=2)
    {
          i0 = 0; i1 = 2;
          j0 = 0; j1 = 2;
    }
    
    //box2
    if (i>=0 && i<=2 && j>=3 && j<=5)
    {
          i0 = 0; i1 = 2;
          j0 = 3; j1 = 5;
    }
    
    //box3
    if (i>=0 && i<=2 && j>=6 && j<=8)
    {
          i0 = 0; i1 = 2;
          j0 = 6; j1 = 8;
    }                        
    
    //box4
    if (i>=3 && i<=5 && j>=0 && j<=2)
    {
          i0 = 3; i1 = 5;
          j0 = 0; j1 = 2;
    }
    
    //box5
    if (i>=3 && i<=5 && j>=3 && j<=5)
    {
          i0 = 3; i1 = 5;
          j0 = 3; j1 = 5;
    }
    
    //box6
    if (i>=3 && i<=5 && j>=6 && j<=8)
    {
          i0 = 3; i1 = 5;
          j0 = 6; j1 = 8;
    }
    
    //box7
    if (i>=6 && i<=8 && j>=0 && j<=2)
    {
          i0 = 6; i1 = 8;
          j0 = 0; j1 = 2;
    }
    
    //box8
    if (i>=6 && i<=8 && j>=3 && j<=5)
    {
          i0 = 6; i1 = 8;
          j0 = 3; j1 = 5;
    }
    
    //box9
    if (i>=6 && i<=8 && j>=6 && j<=8)
    {
          i0 = 6; i1 = 8;
          j0 = 6; j1 = 8;
    }
    
    for (loci=i0; loci<=i1; loci++)
    {
        for (locj=j0; locj<=j1; locj++)
        {                    
            if (loci != i || locj != j)
            {   
                flag1 = 0;         
                if (sudoku[loci][locj]==n)  
                    return 0; 
                else 
                    flag1 = 1;              
            }
        }
    }
    if (flag1==1)  
       return 1; 
    
} //check_box_9x9()
