#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, priority;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int x, int p) {
    struct Node *t = malloc(sizeof(struct Node));
    struct Node *q;

    if (t == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    t->data = x;
    t->priority = p;
    t->next = NULL;

    if (head == NULL || p > head->priority) {
        t->next = head;
        head = t;
    } else {
        q = head;

        while (q->next != NULL &&
               q->next->priority >= p)
            q = q->next;

        t->next = q->next;
        q->next = t;
    }
}

void delete() {
    struct Node *t;

    if (head == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    t = head;
    printf("Deleted: %d\n", t->data);
    head = head->next;
    free(t);
}

void display() {
    struct Node *t = head;

    while (t != NULL) {
        printf("%d(Priority %d) ",
               t->data, t->priority);
        t = t->next;
    }

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
