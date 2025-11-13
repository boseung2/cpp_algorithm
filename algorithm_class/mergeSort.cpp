#include <iostream>
#include <vector>

using namespace std;

long long N = 0;

void merge(vector<int>& a, int p, int q, int r) {
  int i = p;
  int j = q + 1;
  int t = 0;
  vector<int> tmp(r - p + 1);
  while (i <= q && j <= r) {
    if (a[i] < a[j]) {
      N++;
      tmp[t++] = a[i++];
    } else {
      N++;
      tmp[t++] = a[j++];
    }
  }
  while (i <= q) {
    tmp[t++] = a[i++];
  }
  while (j <= r) {
    tmp[t++] = a[j++];
  }
  i = p;
  t = 0;
  while (i <= r) {
    a[i++] = tmp[t++];
  }
}

void merge_sort(vector<int>& a, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }
}

int main(void) {
  int n;
  cin >> n;
  if (n <= 1) {
    cout << 0 << "\n";
    return 0;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  merge_sort(a, 0, n - 1);
  cout << N << "\n";
  return 0;
}
