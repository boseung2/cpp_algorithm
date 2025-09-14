#include<iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  // 더 적은 봉지를 배달해야함
  // 5킬로, 3킬로 봉지
  // 5킬로 먼저 배당하고 나머지 3킬로
  // 떨어지지 않을 때는 5킬로 한개씩 빼면서 3키로로 완성될 때 까지 진행해야함.

  // 5킬로 최대 개수
  int count5 = n / 5;
  while(count5 >= 0) {
    // n - (count5 * 5) 값이 3으로 떨어지면, count3 + count5
    // 안떨어지면, count5--
    int fit = (n - (count5 * 5)) % 3;
    int count3 = (n - (count5 * 5)) / 3;
    if(fit == 0) {
      cout << count5 + count3;
      return 0;
    }
    count5--;
  }
  cout << -1;
}