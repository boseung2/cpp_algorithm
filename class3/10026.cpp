#include <iostream>
#include <queue>

using namespace std;

char graph[101][101];
bool visited1[101][101];
bool visited2[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt1 = 0;
int cnt2 = 0;
int n;

// 일반 시력: 같은 색만 같은 영역
bool sameNormal(char a, char b) { return a == b; }

// 적록색약: R/G를 같은 색 취급, B는 따로
bool sameColorBlind(char a, char b) {
  if (a == 'B' || b == 'B') return a == b;  // B는 B끼리만
  // 나머지는 R, G 섞여도 OK
  return (a == 'R' || a == 'G') && (b == 'R' || b == 'G');
}

void bfs(int sx, int sy, bool visited[101][101], bool colorBlind) {
  queue<pair<int, int>> q;
  visited[sx][sy] = true;
  q.push({sx, sy});

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
      if (visited[nx][ny]) continue;

      char cur = graph[x][y];
      char nxt = graph[nx][ny];

      bool same = colorBlind ? sameColorBlind(cur, nxt) : sameNormal(cur, nxt);
      if (!same) continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }

  // 2중 반복문은 한 번만 돌면서 두 버전 같이 처리
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited1[i][j]) {
        bfs(i, j, visited1, false);  // 일반
        cnt1++;
      }
      if (!visited2[i][j]) {
        bfs(i, j, visited2, true);  // 적록색약
        cnt2++;
      }
    }
  }

  cout << cnt1 << " " << cnt2;
}