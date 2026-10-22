#include <stdio.h>

int isSymmetric(int a[20][20], int n, int i, int j)
{
    if (i == n)
        return 1;

    if (j == n)
        return isSymmetric(a, n, i + 1, 0);

    if (a[i][j] != a[j][i])
        return 0;

    return isSymmetric(a, n, i, j + 1);
}

int main()
{
    int a[20][20], n, i, j;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Invalid matrix order.\n");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    if (isSymmetric(a, n, 0, 0))
        printf("Matrix is symmetric.\n");
    else
        printf("Matrix is not symmetric.\n");

    return 0;
}