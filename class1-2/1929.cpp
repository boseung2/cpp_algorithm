#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n, m;
  cin >> m >> n;

  // n까지 소수 여부를 모두 구한다. - 에라토스테네스의 체
  vector<bool> isPrime(n + 1, true);
  if (n >= 0) isPrime[0] = false;
  if (n >= 1) isPrime[1] = false;
  // n^(1/2)까지 돌면서 배수들을 지운다.
  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
  // m~n 돌면서 소수인 것만 출력한다.
  for (int i = m; i <= n; i++) {
    if (isPrime[i]) {
      cout << i << '\n';
    }
  }

  return 0;
}