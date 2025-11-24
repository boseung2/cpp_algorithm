#include <stdio.h>
#include <unistd.h>

int main(void) {
  int ms;
  int size = 32;

  printf("별표 (*)가 움직이는 속도(밀리초): ");
  scanf("%d", &ms);
  printf("별표가 움직이는 칸수 : %d \n", size);

  while(1) {
    int i=0;
    int j=0;
    for(i=0; i<32; i++) {
      // 줄 초기화
      printf("\r                                   \r");
      // 빈칸을 0~31칸씩 출력
      for(j=0; j<i; j++) {
        printf(" ");
      }
      // 마지막에 * 출력 후 커서 처음으로 이동
      printf("*\r");
      fflush(stdout);
      usleep(ms * 1000);
    }
  }
}