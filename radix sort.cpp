#include <stdio.h>

int getMax(int a[], int n) {
    int max = a[0], i;

    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void countSort(int a[], int n, int exp) {
    int output[100], count[10] = {0};
    int i, digit;

    for (i = 0; i < n; i++) {
        digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

int main() {
    int a[100], n, i, max, exp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter non-negative elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] < 0) {
            printf("Negative numbers are not supported.\n");
            return 0;
        }
    }

    if (n <= 0 || n > 100)
        return 0;

    max = getMax(a, n);

    for (exp = 1; max / exp > 0; exp *= 10) {
        countSort(a, n, exp);
        if (exp > max / 10)
            break;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
