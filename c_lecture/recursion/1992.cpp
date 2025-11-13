#include <iostream>
#include <vector>

using namespace std;

void recursion(vector<vector<int>>& arr, int x, int y, int n) {
  int first = arr[x][y];
  bool same = true;
  for (int i = x; i < x + n; i++) {
    for (int j = y; j < y + n; j++) {
      if (arr[i][j] != first) {
        same = false;
        break;
      }
    }
  }
  // 모두 같은 수일 때
  // 첫 번째 수 출력
  if (same) {
    cout << first;
    return;
  }
  // 모두 같지 않을 때
  // 4등분으로 나누어 재귀 호출
  cout << "(";
  int half = n / 2;
  recursion(arr, x, y, half);                // 1사분면
  recursion(arr, x, y + half, half);         // 2사분면
  recursion(arr, x + half, y, half);         // 3사분면
  recursion(arr, x + half, y + half, half);  // 4사분
  cout << ")";
}

int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < n; j++) {
      arr[i][j] = line[j] - '0';
    }
  }
  recursion(arr, 0, 0, n);
  return 0;
}