#include <stdio.h>

void reverse(int a[], int start, int end)
{
    int temp;

    if (start >= end)
        return;

    temp = a[start];
    a[start] = a[end];
    a[end] = temp;

    reverse(a, start + 1, end - 1);
}

int main()
{
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid array size.");
        return 0;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    reverse(a, 0, n - 1);

    printf("Reversed array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}