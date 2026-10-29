#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

int isFull() {
    return (rear + 1) % MAX == front;
}

int isEmpty() {
    return front == -1;
}

void insertFront(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        front = (front - 1 + MAX) % MAX;

    q[front] = x;
}

void insertRear(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    q[rear] = x;
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", q[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", q[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear = (rear - 1 + MAX) % MAX;
}

void display() {
    int i;

    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    i = front;

    while (1) {
        printf("%d ", q[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int ch, x;

    do {
        printf("\n1.Insert Front 2.Insert Rear");
        printf("\n3.Delete Front 4.Delete Rear");
        printf("\n5.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                scanf("%d", &x);
                insertRear(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
