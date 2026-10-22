#include <stdio.h>

int columnSum(int a[20][20], int rows, int col, int i)
{
    if (i == rows)
        return 0;

    return a[i][col] + columnSum(a, rows, col, i + 1);
}

int findMinColumn(int a[20][20], int rows, int cols,
                  int col, int minCol, int minSum)
{
    if (col == cols)
        return minCol;

    int sum = columnSum(a, rows, col, 0);

    if (sum < minSum)
    {
        minSum = sum;
        minCol = col;
    }

    return findMinColumn(a, rows, cols, col + 1,
                         minCol, minSum);
}

int main()
{
    int a[20][20], rows, cols, i, j;
    int minCol, minSum;

    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &cols);

    if (rows <= 0 || rows > 20 ||
        cols <= 0 || cols > 20)
    {
        printf("Invalid matrix size.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    minSum = columnSum(a, rows, 0, 0);
    minCol = 0;

    minCol = findMinColumn(a, rows, cols, 1,
                           minCol, minSum);

    printf("Column with minimum sum = %d\n", minCol + 1);
    printf("Minimum sum = %d\n",
           columnSum(a, rows, minCol, 0));

    return 0;
}