#include <stdio.h>
#define MAX 100

int heap[MAX], n = 0;

void insert(int x) {
    int i, temp;

    if (n == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    i = n++;
    heap[i] = x;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void deleteMax() {
    int i = 0, left, right, largest, temp;

    if (n == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted highest priority: %d\n", heap[0]);
    heap[0] = heap[--n];

    while (1) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;

        if (left < n && heap[left] > heap[largest])
            largest = left;

        if (right < n && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }
}

void display() {
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    int ch, x;

    do {
        printf("\n1.Insert 2.Delete Max 3.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value/priority: ");
                scanf("%d", &x);
                insert(x);
                break;
            case 2:
                deleteMax();
                break;
            case 3:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
