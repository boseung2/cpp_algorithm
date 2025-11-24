#include <iostream>

using namespace std;

int main(void) {
  long long n, m;
  cin >> n >> m;
  long long result = n - m;
  // result가 0이상이면 크면 출력
  // result가 음수면 -로 출력
  if (result >= 0) {
    cout << result << "\n";
  } else {
    cout << -result << "\n";
  }
}