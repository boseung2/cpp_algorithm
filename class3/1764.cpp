#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> a, b, c;
int cnt;

int main(void) {
  int n, m;
  cin >> n >> m;

  a.resize(n);
  b.resize(m);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] == b[j]) {
      c.push_back(a[i]);
      cnt++;
      i++;
      j++;
    } else if (a[i] < b[j]) {
      i++;
    } else {
      j++;
    }
  }

  cout << cnt << "\n";
  for (int i = 0; i < c.size(); i++) {
    cout << c[i] << "\n";
  }
}