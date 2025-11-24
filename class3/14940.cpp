#include <iostream>
#include <queue>

using namespace std;

int n, m;
int graph[1001][1001];
int dist[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void) {
  cin >> n >> m;
  int sx, sy;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> graph[i][j];
      dist[i][j] = -1;
      if (graph[i][j] == 2) {
        sx = i;
        sy = j;
      }
      if (graph[i][j] == 0) {
        dist[i][j] = 0;
      }
    }
  }
  queue<pair<int, int>> q;
  q.push({sx, sy});
  dist[sx][sy] = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    int x = cur.first;
    int y = cur.second;

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (graph[nx][ny] == 0) continue;
      if (dist[nx][ny] != -1) continue;

      dist[nx][ny] = dist[x][y] + 1;
      q.push({nx, ny});
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
}