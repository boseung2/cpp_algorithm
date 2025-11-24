#include <stdio.h>
#include <unistd.h>

int main(void) {
  int ms;
  int size = 32;
  int cnt = 1;

  printf("별표 (*)가 움직이는 속도(밀리초): ");
  scanf("%d", &ms);
  printf("별표가 움직이는 칸수 : %d \n", size);

  while(1) {
    int i=0;
    int j=0;
    // 좌 -> 우
    for(i=0; i<size-cnt; i++) {
      // 줄 초기화
      printf("\r");
      for(int i=0; i<size; i++) {
        printf(" ");
      }
      printf("\r");

      // 빈칸을 0~31칸씩 출력
      for(j=0; j<i; j++) {
        printf(" ");
      }
      
      // 마지막에 * 출력 후 커서 처음으로 이동
      for(int i=0; i<cnt; i++) {
        printf("*");
      }
      printf("\r");
      fflush(stdout);
      usleep(ms * 1000);
    }
    // 별 개수 추가
    // 개수가 size를 넘어가면 1로 초기화
    cnt++;
    if (cnt > size) {
      cnt = 1;
    }
    // 우 -> 좌
    for(int i=size-cnt; i>=0; i--) {
      // 줄 초기화
      printf("\r");
      for(int i=0; i<size; i++) {
        printf(" ");
      }
      printf("\r");

      for(j=0; j<i; j++) {
        printf(" ");
      }
      
      for(int i=0; i<cnt; i++) {
        printf("*"); 
      }
      printf("\r");
      fflush(stdout);
      usleep(ms * 1000);
    }
    cnt++;
    if (cnt > size) {
      cnt = 1;
    }
  }
}