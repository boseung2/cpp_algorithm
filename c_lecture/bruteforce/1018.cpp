#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  // n x m 2차원 배열 입력받기
  vector<vector<char>> arr(n, vector<char>(m));
  string line;
  for (int i = 0; i < n; i++) {
    cin >> line;
    for (int j = 0; j < m; j++) {
      arr[i][j] = line[j];
    }
  }
  // 8x8 체스판으로 자른다.
  // (0, 0)에서 시작해서 (n-8, m-8)까지 자를 수 있다.
  // 최대 변경 횟수는 64
  // (i, j)에서 시작하는 8x8 체스판 자르기
  int min_changes = 64;
  for (int i = 0; i <= n - 8; i++) {
    for (int j = 0; j <= m - 8; j++) {
      // W로 시작하는 경우의 변경 횟수
      int changes = 0;
      for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
          // 현재 칸의 예상 색깔 계산 (W로 시작하는 경우)
          char expected = ((x + y) % 2 == 0) ? 'W' : 'B';
          if (arr[i + x][j + y] != expected) {
            changes++;
          }
        }
      }
      // 변경횟수가 32보다 크면 반대색으로 시작하는 경우가 더 적은 변경횟수를 가짐
      changes = min(changes, 64 - changes);
      min_changes = min(min_changes, changes);
    }
  }
  cout << min_changes << "\n";
}