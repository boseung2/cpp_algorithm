#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  // a 배열 정렬
  sort(a.begin(), a.end());

  // B 값을 기준으로 내림차순 정렬
  vector<pair<int, int>> b_info;  // {B값, 인덱스}
  for (int i = 0; i < n; i++) {
    b_info.push_back({b[i], i});
  }
  sort(b_info.begin(), b_info.end(),
       [](const pair<int, int>& x, const pair<int, int>& y) { return x.first > y.first; });

  // a 가장 작은 값부터 b 큰 값에 매칭
  vector<int> a_new(n);
  for (int i = 0; i < n; i++) {
    int idx = b_info[i].second;
    a_new[idx] = a[i];
  }

  int result = 0;
  for (int i = 0; i < n; i++) {
    result += a_new[i] * b[i];
  }

  cout << result << "\n";
  return 0;
}
