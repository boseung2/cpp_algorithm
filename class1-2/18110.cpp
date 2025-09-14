#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  vector<int> a;
  cin >> n;
  a.resize(n);
  if (n == 0) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // a 정렬
  sort(a.begin(), a.end());
  // sub -> a.length()의 15%를 구하고 반올림 한 수
  // avg -> a에서 sub 앞, 뒤에서 뺀 애들 중 평균 (반올림)
  int sub = (int)floor(a.size() * 0.15 + 0.5);
  if (sub > 0 && sub * 2 < a.size()) {
    a.erase(a.begin(), a.begin() + sub);
    a.erase(a.end() - sub, a.end());
  }
  int sum = 0;
  for (int num : a) {
    sum += num;
  }
  int avg = (int)floor((double)sum / a.size() + 0.5);
  cout << avg << "\n";
}