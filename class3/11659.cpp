#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<long long> sum;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  arr.resize(n + 1);
  sum.resize(n + 1);

  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    sum[i] = sum[i - 1] + arr[i];
  }

  while (m--) {
    int i, j;
    cin >> i >> j;
    long long result = sum[j] - sum[i - 1];
    cout << result << "\n";
  }
}