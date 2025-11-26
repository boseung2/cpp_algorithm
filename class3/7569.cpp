#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int m, n, h;
int graph[101][101][101];
int day[101][101][101];
bool visited[101][101][101];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int maxDay = 0;

int main(void) {
  cin >> m >> n >> h;
  for (int z = 0; z < h; z++) {
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        cin >> graph[z][y][x];
      }
    }
  }

  queue<tuple<int, int, int>> q;

  // 1을 큐에 모두 넣는다.
  for (int z = 0; z < h; z++) {
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        if (graph[z][y][x] == 1) {
          q.push({z, y, x});
          visited[z][y][x] = true;
          day[z][y][x] = 0;
        }
      }
    }
  }

  // bfs 돌면서 거리 센다.
  while (!q.empty()) {
    int z, y, x;
    tie(z, y, x) = q.front();
    q.pop();

    for (int dir = 0; dir < 6; dir++) {
      int nz = z + dz[dir];
      int ny = y + dy[dir];
      int nx = x + dx[dir];

      if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

      if (graph[nz][ny][nx] != 0) continue;
      if (visited[nz][ny][nx]) continue;

      visited[nz][ny][nx] = true;
      graph[nz][ny][nx] = 1;
      day[nz][ny][nx] = day[z][y][x] + 1;
      maxDay = max(maxDay, day[nz][ny][nx]);
      q.push({nz, ny, nx});
    }
  }

  // 안익은 토마토 있으면 -1
  for (int z = 0; z < h; z++) {
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        if (graph[z][y][x] == 0) {
          cout << -1 << "\n";
          return 0;
        }
      }
    }
  }

  cout << maxDay << "\n";
}