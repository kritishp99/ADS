#include <stdio.h>
#define MAX 100

int undo[MAX], redo[MAX];
int tu = -1, tr = -1, current = 0;

int main() {
    int ch, x;

    do {
        printf("\n1.New State 2.Undo 3.Redo 4.Current 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter new state: ");
                scanf("%d", &x);

                if (tu < MAX - 1 && tr < MAX - 1) {
                    undo[++tu] = current;
                    current = x;
                    tr = -1;
                } else {
                    printf("Stack capacity reached\n");
                }
                break;

            case 2:
                if (tu == -1)
                    printf("Nothing to undo\n");
                else {
                    redo[++tr] = current;
                    current = undo[tu--];
                }
                break;

            case 3:
                if (tr == -1)
                    printf("Nothing to redo\n");
                else {
                    undo[++tu] = current;
                    current = redo[tr--];
                }
                break;

            case 4:
                printf("Current state: %d\n", current);
                break;
        }
    } while (ch != 0);

    return 0;
}
