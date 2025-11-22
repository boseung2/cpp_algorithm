#include <iostream>

using namespace std;

int dp[1001];

int main(void) {
  int n;
  cin >> n;
  /*
    dp[1] = 1
    dp[2] = 3
    dp[3] = 5 (dp[2] + 2*dp[1])
    dp[4] = 11 (dp[3] + 2*dp[2])
    dp[5] = 21 (dp[4] + 2*dp[3])
    dp[6] = dp[5] + 2*dp[4] = 21 + 22 = 43
    dp[7] = dp[6] + 2*dp[5] = 43 + 42 = 85
    dp[8] = dp[7] + 2*dp[6] = 85 + 86 = 171
  */
  dp[1] = 1;
  dp[2] = 3;
  for (int i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
  }

  cout << dp[n] << "\n";
}