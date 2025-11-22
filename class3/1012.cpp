#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int graph[50][50] = {0};
bool visited[50][50] = {false};
int cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int sx, int sy, int m, int n) {
  queue<pair<int, int>> q;
  q.push({sx, sy});
  visited[sx][sy] = true;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    int x = cur.first;
    int y = cur.second;

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      if (visited[nx][ny]) continue;
      if (graph[nx][ny] == 0) continue;

      visited[nx][ny] = true;
      q.push({nx, ny});
    }
  }
}

int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int m, n, k;
    cin >> m >> n >> k;

    memset(graph, 0, sizeof(graph));
    memset(visited, false, sizeof(visited));
    cnt = 0;

    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      graph[a][b] = 1;
    }

    for (int x = 0; x < m; x++) {
      for (int y = 0; y < n; y++) {
        if (graph[x][y] == 1 && !visited[x][y]) {
          bfs(x, y, m, n);
          cnt++;
        }
      }
    }
    cout << cnt << "\n";
  }
}