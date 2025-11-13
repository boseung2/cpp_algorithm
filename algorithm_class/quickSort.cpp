#include <iostream>
#include <vector>

using namespace std;

int N = 0;

int partition(vector<int>& a, int p, int r) {
  int x = a[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (a[j] <= x) {
      i++;
      swap(a[i], a[j]);
      N++;
    }
  }
  N++;
  swap(a[i + 1], a[r]);
  return i + 1;
}

void quick_sort(vector<int>& a, int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quick_sort(a, p, q - 1);
    quick_sort(a, q + 1, r);
  }
}

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  quick_sort(a, 0, n - 1);
  cout << N << "\n";
  return 0;
}