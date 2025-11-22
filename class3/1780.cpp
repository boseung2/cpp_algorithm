#include <iostream>
#include <vector>

using namespace std;

int minus1 = 0;
int zero = 0;
int plus1 = 0;

bool check(vector<vector<int>>& arr, int x, int y, int n) {
  int first = arr[x][y];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[x + i][y + j] != first) {
        int m = n / 3;
        check(arr, x, y, m);
        check(arr, x, y + m, m);
        check(arr, x, y + 2 * m, m);
        check(arr, x + m, y, m);
        check(arr, x + m, y + m, m);
        check(arr, x + m, y + 2 * m, m);
        check(arr, x + 2 * m, y, m);
        check(arr, x + 2 * m, y + m, m);
        check(arr, x + 2 * m, y + 2 * m, m);
        return false;
      }
    }
  }
  if (first == -1) {
    minus1++;
  } else if (first == 0) {
    zero++;
  } else {
    plus1++;
  }
  return true;
}

int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  // 1. n x n 칸이 모두 같은지 확인
  check(arr, 0, 0, n);
  // 2. 모두 같은 경우: 해당 숫자 출력 후 종료
  // 3. 모두 같지 않은 경우: 9등분

  // 4. 1~3 반복
  // 5. 종료 조건: 1칸이 되었을 때
  cout << minus1 << "\n" << zero << "\n" << plus1 << "\n";
  return 0;
}