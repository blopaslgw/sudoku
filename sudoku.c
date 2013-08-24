# include <stdio.h>
# define SIZE 9
# define NMAX 9

int sudoku[SIZE][SIZE];
int TempArr[SIZE][SIZE];

void printSudokuGrid(void)
{
    int i, j;
    char* index = "    0 1 2  3 4 5  6 7 8\n";
    char* underline = "  + - - -+ - - -+ - - - +\n";
    char* vertLine = "|";
    
    printf("\n%s", index);
    
    for(i = 0; i < SIZE; i++)
    {
        printf("%s%d %s", (i % 3 == 0) ? underline : "", i, vertLine);  
        for (j = 0; j < SIZE; j++)
            printf("%s %d", (j % 3 == 0 && j != 0) ? vertLine : "", sudoku[i][j]);
        printf(" %s\n", vertLine);
    }
    printf("%s", underline);
}
    
int getSudokoGrid(void)
{
    int i, j;
    char str[81];
    FILE* ip_file;
    
    printf("Welcome to Sudoku Solver\n"
    "Input file: ");
    scanf("%s", str);
    
    if((ip_file = fopen(str, "r")) == NULL)
    {
        perror("Sorry, could not open the file\n");
        getchar();
        return 1;
    }
    
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
        {
            if(fscanf(ip_file, "%d", &sudoku[i][j]) == 1)
                TempArr[i][j] = sudoku[i][j];
            else
            {
                perror("fscanf failed on input file\n");
                return 1;
            }
        }
        
    fclose(ip_file);
    printf("Your input\n");
    printSudokuGrid();
    return 0;
}


int check_box(int i, int j, int n)
{
    int iwalk, jwalk;
    
    for(iwalk = (i/3)*3; iwalk < (i/3)*3 + 3; iwalk++)
        for(jwalk = (j/3)*3; jwalk < (j/3)*3 + 3; jwalk++)
            if( !(iwalk==i && jwalk == j) &&
                sudoku[iwalk][jwalk]==n)
                    return 0;
    
    return 1;
}

int check_row_column (int i, int j, int n)
{
    int walk;
    for (walk = 0; walk < SIZE; walk++)
        if (sudoku[i][walk]==n || sudoku[walk][j]==n)
            return 0;

    return 1;
}

int check(int i, int j, int n)
{
    if(check_row_column(i,j,n) == 1 &&
        check_box(i,j,n) == 1)
            return 1;
    else
        return 0;
}

int backTrack(int *pos_i, int *pos_j, int *num)
{
    int i, j;
    int j_begin = *pos_j;
    
    for(i = *pos_i; i >= 0; i--)
        for(j = j_begin; j >= 0; j--)
        {
            j_begin = 9;
            if(!(i == *pos_i && j == *pos_j) && TempArr[i][j] == 0)
            {
                if(sudoku[i][j] == NMAX)
                    sudoku[i][j] = 0;
                else
                {
                    *num = sudoku[i][j];
                    sudoku[i][j] = 0;
                    *pos_i = i;
                    *pos_j = j;
                    return 1;
                }
            }
        }
}

int solveGrid(void)
{
    int flag;
    int i, j, n;
    
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            if(sudoku[i][j] == 0)
                for(n = 1; n <= NMAX; n++)
                {
                    if(check(i, j, n) == 1)
                    {
                        sudoku[i][j] = n;
                        break;
                    }
                    
                    else if(n == NMAX)
                        backTrack(&i, &j, &n);
                    
                }
    return 0;
}

main()
{
    getSudokoGrid();
    solveGrid();
    printSudokuGrid();
    getchar();
}
