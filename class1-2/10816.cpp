#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n, m;
  vector<int> a;
  vector<int> b;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  b.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());

  for (int num : b) {
    auto low = lower_bound(a.begin(), a.end(), num);
    auto up = upper_bound(a.begin(), a.end(), num);
    cout << up - low << " ";
  }
}