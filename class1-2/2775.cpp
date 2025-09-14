#include<iostream>

using namespace std;

int main(void) {
  // 0층 그대로 입력
  int t;
  int dp[15][15] = {0};

  for(int i=1; i<=14; i++) {
    dp[0][i] = i;
  }

  // dp[k][n]은 (같은 층 앞 호수 + 아랫 층 같은 호수)
  for(int k=1; k<=14; k++) {
    for(int n=1; n<=14; n++) {
      dp[k][n] = dp[k][n-1] + dp[k-1][n];
    }
  }

  cin >> t;
  for(int i=0; i<t; i++) {
    int k, n;
    cin >> k >> n;
    cout << dp[k][n] << endl;
  }
}