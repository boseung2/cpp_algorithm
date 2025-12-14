#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ms;

#define WIDTH 33
#define XMAX (WIDTH - 1)
#define YMIN 1
#define YMAX 5

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
}

void clear_except_top(void) {
    printf("\033[2;1H");
    printf("\033[J");
    fflush(stdout);
}

void printStar(int x, int y) {
    gotoxy(x, y);
    putchar('*');
    fflush(stdout);
    usleep(ms * 1000);
}

int main(int argc, char *argv[]) {
    printf("Start!! column size: %d, 별표(*)속도(ms) : ", WIDTH);
    if (scanf("%d", &ms) != 1) return 0;

    gotoxy(0, 0);
    printf("start!! column size: %d, 별표(*)속도(ms) : %d", WIDTH, ms);
    fflush(stdout);

    while (1) {
        int i, j;

        j = YMIN;
        for (i = 0; i < WIDTH; i++) {
            clear_except_top();
            printStar(i, j);
        }

        i = XMAX;
        for (j = YMIN; j <= YMAX; j++) {
            clear_except_top();
            printStar(i, j);
        }

        j = YMAX;
        for (i = XMAX; i >= 0; i--) {
            clear_except_top();
            printStar(i, j);
        }

        i = 0;
        for (j = YMAX; j >= YMIN; j--) {
            clear_except_top();
            printStar(i, j);
        }

        i = 0;
        for (j = YMIN; j <= YMAX; j++) {
            clear_except_top();
            printStar(i, j);
        }

        j = YMAX;
        for (i = 0; i <= XMAX; i++) {
            clear_except_top();
            printStar(i, j);
        }

        i = XMAX;
        for (j = YMAX; j >= YMIN; j--) {
            clear_except_top();
            printStar(i, j);
        }

        j = YMIN;
        for (i = XMAX; i >= 0; i--) {
            clear_except_top();
            printStar(i, j);
        }
    }

    return 0;
}