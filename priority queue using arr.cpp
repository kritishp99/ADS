#include <stdio.h>
#define MAX 100

int data[MAX], priority[MAX], n = 0;

void insert(int x, int p) {
    int i;

    if (n == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    i = n - 1;

    while (i >= 0 && priority[i] < p) {
        data[i + 1] = data[i];
        priority[i + 1] = priority[i];
        i--;
    }

    data[i + 1] = x;
    priority[i + 1] = p;
    n++;
}

void delete() {
    int i;

    if (n == 0) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", data[0]);

    for (i = 0; i < n - 1; i++) {
        data[i] = data[i + 1];
        priority[i] = priority[i + 1];
    }

    n--;
}

void display() {
    int i;

    for (i = 0; i < n; i++)
        printf("%d(Priority %d) ", data[i], priority[i]);

    printf("\n");
}

int main() {
    int ch, x, p;

    do {
        printf("\n1.Insert 2.Delete 3.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d%d", &x, &p);
                insert(x, p);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
