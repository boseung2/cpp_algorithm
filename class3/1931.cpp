#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> arr;

int main(void) {
  int n;
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr[i] = {a, b};
  }

  sort(arr.begin(), arr.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
  });

  int start = arr[0].first;
  int end = arr[0].second;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i].first < end) continue;
    start = arr[i].first;
    end = arr[i].second;
    cnt++;
  }

  cout << cnt << "\n";
}