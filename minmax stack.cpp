#include <stdio.h>
#define MAX 100

int a[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        a[++top] = x;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted: %d\n", a[top--]);
}

void minMax() {
    int i, min, max;

    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    min = max = a[0];

    for (i = 1; i <= top; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }

    printf("Minimum = %d\nMaximum = %d\n", min, max);
}

void display() {
    int i;

    for (i = top; i >= 0; i--)
        printf("%d ", a[i]);

    printf("\n");
}

int main() {
    int ch, x;

    do {
        printf("\n1.Push 2.Pop 3.Min-Max 4.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                minMax();
                break;
            case 4:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
