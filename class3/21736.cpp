#include <iostream>
#include <queue>

using namespace std;

int n, m;
char graph[601][601];
bool visited[601][601];
int cnt = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = true;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();
    int cx = cur.first;
    int cy = cur.second;

    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];

      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (visited[nx][ny]) continue;
      if (graph[nx][ny] == 'X') continue;

      q.push({nx, ny});
      visited[nx][ny] = true;
      if (graph[nx][ny] == 'P') {
        cnt++;
      }
    }
  }
}

int main(void) {
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> graph[i][j];
      if (graph[i][j] == 'I') {
        x = i;
        y = j;
      }
    }
  }
  bfs(x, y);

  if (cnt == 0) {
    cout << "TT" << "\n";
  } else {
    cout << cnt << "\n";
  }
}