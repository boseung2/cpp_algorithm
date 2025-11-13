#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int m, n;
  cin >> m >> n;
  vector<bool> is_prime(n + 1, false);
  is_prime[0] = is_prime[1] = true;  // 0과 1은 소수가 아님
}