#include <algorithm>
#include <iostream>

using namespace std;

int score[301];
int dp[301];

int solve(int i) {
  if (dp[i] != -1) return dp[i];

  if (i == 1) return dp[1] = score[1];
  if (i == 2) return dp[2] = score[1] + score[2];
  if (i == 3) return dp[3] = max(score[1] + score[3], score[2] + score[3]);

  return dp[i] = max(solve(i - 2) + score[i], solve(i - 3) + score[i - 1] + score[i]);
}

int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> score[i];
  }

  // bottom-up
  // if (n >= 1) dp[1] = score[1];
  // if (n >= 2) dp[2] = score[1] + score[2];
  // if (n >= 3) dp[3] = max(score[1] + score[3], score[2] + score[3]);

  // for (int i = 4; i <= n; i++) {
  //   dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
  // }

  memset(dp, -1, sizeof(dp));

  // top-down + memoization
  cout << solve(n) << "\n";
  return 0;
}