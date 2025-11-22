#include <iostream>

using namespace std;

int dp[1001];

int main(void) {
  int n;
  cin >> n;
  /*
  dp[1] = 1
  dp[2] = 2
  dp[3] = 3 (dp[2] + dp[1])
  dp[4] = 5 (dp[3] + dp[2])
  dp[5] = 8 (dp[4] + dp[3])
  */

  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
  }

  cout << dp[n];
}