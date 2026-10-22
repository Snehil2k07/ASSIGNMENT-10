#include <stdio.h>
#include <limits.h>

void findLargest(int a[], int n, int i,
                 int *largest, int *second)
{
    if (i == n)
        return;

    if (a[i] > *largest)
    {
        *second = *largest;
        *largest = a[i];
    }
    else if (a[i] < *largest && a[i] > *second)
    {
        *second = a[i];
    }

    findLargest(a, n, i + 1, largest, second);
}

int main ()
{
    int a[100], n, i;
    int largest = INT_MIN;
    int second = INT_MIN;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
         printf("Invalid array size. ");
         return 0;
      return 0;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    findLargest(a, n, 0, &largest, &second);

    if (second == INT_MIN)
        printf("Fewer than two distinct elements exist.");
    else
        printf("Second-largest distinct element = %d", second);

    return 0;
}