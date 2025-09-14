#include<iostream>

using namespace std;

int main(void) {
  // 높이 V
  // 낮 - +A, 밤 -B
  // 정상에서는 안미끄러짐
  int a, b, v;
  cin >> a >> b >> v;

  // v-a 까지 걸리는 일수 +하루
  // 하루에 올라가는 길이 a-b
  // 하루 전날 v-a 보다 위, v-b보다 같거나 아래에 있으면 됨
  //int result = ceil((v-a) / (float)(a-b)) + 1;
  int result = (v - b - 1) / (a - b) + 1;
  
  cout << result;
}