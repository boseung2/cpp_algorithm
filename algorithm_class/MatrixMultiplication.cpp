#include <cstring>
#include <iostream>
using namespace std;

int n;
int r[501], c[501];
long long dp[501][501];

long long matrixChain(int i, int j) {
  if (i == j) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  long long best = (1LL << 62);

  for (int k = i; k < j; k++) {
    long long left = matrixChain(i, k);
    long long right = matrixChain(k + 1, j);
    long long cost = left + right + 1LL * r[i] * c[k] * c[j];

    if (cost < best) best = cost;
  }

  dp[i][j] = best;
  return best;
}

int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> c[i];
  }

  memset(dp, -1, sizeof(dp));
  cout << matrixChain(0, n - 1) << "\n";
}