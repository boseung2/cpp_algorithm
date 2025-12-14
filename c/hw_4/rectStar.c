#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define WIDTH 33
int ms;

void gotoxy(int x, int y) {
    // ANSI escape sequence: y행 x열 (1부터 시작)
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
}

void printStar(int x, int y) {
    gotoxy(x, y);
    printf("*");
    fflush(stdout);
    usleep(ms * 1000);
}

void clear_except_top(void) {
    // Move cursor to the second line (row 2, col 1)
    printf("\033[2;1H");
    // Clear from cursor to the end of the screen
    printf("\033[J");
    fflush(stdout);
}

int main(int argc, char *argv[]) {
  printf("Start!! column size: %d, 별표(*)속도(ms) : ", WIDTH);
  scanf("%d", &ms);

  gotoxy(0, 0);
  printf("start!! column size: %d, 별표(*)속도(ms) : %d", WIDTH, ms);
  fflush(stdout);

  while(1) {
    int i, j;

    j = 1;
    for(i = 0; i < WIDTH; i++) {
      printStar(i, j);
      clear_except_top();
    }

    i = WIDTH - 1;
    for(j = 1; j <= 5; j++) {
      printStar(i, j);
      clear_except_top();
    }

    j = 5;
    for(i = WIDTH - 1; i >= 0; i--) {
      printStar(i, j);
      clear_except_top();
    }

    i = 0;
    for(j = 5; j >= 1; j--) {
      printStar(i, j);
      clear_except_top();
    }
  }
}