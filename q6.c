#include <stdio.h>

int findMax(int a[], int n)
{
    if (n == 1)
        return a[0];

    int max = findMax(a, n - 1);

    if (a[n - 1] > max)
        return a[n - 1];
    else
        return max;
}

int countOccurrences(int a[], int n, int max)
{
    if (n == 0)
        return 0;

    if (a[n - 1] == max)
        return 1 + countOccurrences(a, n - 1, max);
    else
        return countOccurrences(a, n - 1, max);
}

int main()
{
    int a[100], n, i, max, count;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n <= 0 || n > 100)
    {
        printf("Invalid array size.\n");
        return 0;
    }

    max = findMax(a, n);
    count = countOccurrences(a, n, max);

    printf("Maximum element = %d\n", max);
    printf("Number of occurrences = %d\n", count);

    return 0;
}