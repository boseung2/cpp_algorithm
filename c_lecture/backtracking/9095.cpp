#include <iostream>
#include <vector>

using namespace std;

int pick[11];
int n;
int ans = 0;

int dfs(int sum) {
  if (sum == n) {
    ans++;
    return 0;
  }
  if (sum > n) {
    return 0;
  }
  for (int step : {1, 2, 3}) {
    dfs(sum + step);
  }
  return 0;
}

int main(void) {
  int t;
  cin >> t;
  vector<int> arr(t);
  for (int i = 0; i < t; i++) {
    cin >> n;
    ans = 0;
    dfs(0);
    cout << ans << "\n";
  }

  return 0;
}