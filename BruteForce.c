# include <stdio.h>
# include "lib.h"

extern int sudoku[size][size];
extern int TempArr[size][size];
       int I, J, N;
       
int BruteForce (void)
{
    int flag1;
   
    for (I=0; I<size; I++)
    {    
         for (J=0; J<size; J++)
         {     
               if (sudoku[I][J]==0)
               {      
                      for (N=1; N<nmax; N++)
                      {                              
                                                     if (check(I,J,N)==1)
                                                     {    
                                                           sudoku[I][J]=N;
                                                           break;
                                                     }
                                                     else if (N==nmax-1)
                                                           back();
                      }
               }
         }
   }
   
}//BruteForceAlgo() 


int back(void)
{
      int bki,bkj,flag2=0;
      int jback = J;
      
      for (bki=I; bki>=0; bki--)
      {    
           for (bkj=jback; bkj>=0; bkj--)
           {               
                           jback=9;    
                           if (!(bki==I && bkj==J) && TempArr[bki][bkj]==0)
                           {                              
                                      flag2=0;                                   
                                      if (sudoku[bki][bkj]==nmax-1) 
                                             sudoku[bki][bkj]=0; 
                                      else 
                                      {
                                           N=sudoku[bki][bkj];
                                           sudoku[bki][bkj]=0; 
                                           I = bki; J = bkj;
                                           flag2=1;
                                           break;
                                      }
                           }
            }
            if (flag2==1) 
                break; 
      }
      
} //back()
                         
        

