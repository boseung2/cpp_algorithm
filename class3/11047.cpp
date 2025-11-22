#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

int main(void) {
  int n, k;
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > k) continue;
    cnt += k / a[i];
    k %= a[i];
  }

  cout << cnt << "\n";
  return 0;
}