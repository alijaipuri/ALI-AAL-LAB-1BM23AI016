#include <stdio.h>
#include <math.h>

int board[20], count,i;

int place(int row, int column) {
    for (i = 1; i < row; i++)
        if (board[i] == column || abs(board[i] - column) == abs(i - row))
            return 0;
    return 1;
}
void printSolution(int n) {
    printf("\nSolution %d:\n", ++count);
    int i,j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
}
void nQueens(int row, int n) {
	int column;
    for (column = 1; column <= n; column++) {
        if (place(row, column)) {
board[row] = column;
            if (row == n)
                printSolution(n);
            else
                nQueens(row + 1, n);
        }
    }
}

int main() {
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);

    count = 0;
    nQueens(1, n);
    printf("\nTotal Solutions = %d\n", count);

    return 0;
}

/*Output
Enter number of queens: 4

Solution 1:
- Q - - 
- - - Q 
Q - - - 
- - Q - 

Solution 2:
- - Q - 
Q - - - 
- - - Q 
- Q - - 

Total Solutions = 2
*/
