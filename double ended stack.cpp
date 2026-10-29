#include <stdio.h>
#define MAX 100

int a[MAX], top1 = -1, top2 = MAX;

void push1(int x) {
    if (top1 + 1 == top2)
        printf("Stack Overflow\n");
    else
        a[++top1] = x;
}

void push2(int x) {
    if (top1 + 1 == top2)
        printf("Stack Overflow\n");
    else
        a[--top2] = x;
}

void pop1() {
    if (top1 == -1)
        printf("Stack 1 Underflow\n");
    else
        printf("Deleted: %d\n", a[top1--]);
}

void pop2() {
    if (top2 == MAX)
        printf("Stack 2 Underflow\n");
    else
        printf("Deleted: %d\n", a[top2++]);
}

void display(int start, int end) {
    int i;

    for (i = start; i <= end; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main() {
    int ch, x;

    do {
        printf("\n1.Push Stack1 2.Pop Stack1");
        printf("\n3.Push Stack2 4.Pop Stack2");
        printf("\n5.Display Stack1 6.Display Stack2 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                push1(x);
                break;
            case 2:
                pop1();
                break;
            case 3:
                scanf("%d", &x);
                push2(x);
                break;
            case 4:
                pop2();
                break;
            case 5:
                display(0, top1);
                break;
            case 6:
                display(top2, MAX - 1);
                break;
        }
    } while (ch != 0);

    return 0;
}
