#include <bits/stdc++.h>
using namespace std;

int whiteCnt = 0, blueCnt = 0;

// arr의 (x, y)를 좌상단으로 하는 len x len 구간을 검사해서
// 단색이면 카운트하고, 아니면 4등분하여 재귀
void cut(const vector<vector<int>>& arr, int x, int y, int len) {
  int first = arr[x][y];
  bool same = true;
  for (int i = x; i < x + len && same; ++i) {
    for (int j = y; j < y + len; ++j) {
      if (arr[i][j] != first) {
        same = false;
        break;
      }
    }
  }
  if (same) {
    if (first == 0)
      ++whiteCnt;
    else
      ++blueCnt;
    return;
  }
  int h = len / 2;
  cut(arr, x, y, h);
  cut(arr, x, y + h, h);
  cut(arr, x + h, y, h);
  cut(arr, x + h, y + h, h);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  if (!(cin >> N)) return 0;
  vector<vector<int>> arr(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
    }
  }

  cut(arr, 0, 0, N);
  cout << whiteCnt << '\n' << blueCnt << '\n';
  return 0;
}