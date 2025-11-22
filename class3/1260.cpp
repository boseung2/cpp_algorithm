#include <iostream>
#include <queue>

using namespace std;

int graph[1001][1001] = {0};
bool visited[1001] = {false};
int n, m, v;

void bfs(int start) {
  queue<int> q;
  fill(visited, visited + 1001, false);

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int x = q.front();
    q.pop();
    cout << x << " ";

    for (int i = 1; i <= n; i++) {
      if (graph[x][i] == 1 && !visited[i]) {
        visited[i] = true;
        q.push(i);
      }
    }
  }
}

void dfs(int start) {
  cout << start << " ";
  visited[start] = true;

  for (int i = 1; i <= n; i++) {
    if (graph[start][i] == 1 && !visited[i]) {
      dfs(i);
    }
  }
}

int main(void) {
  cin >> n >> m >> v;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a][b] = graph[b][a] = 1;
  }

  dfs(v);
  cout << "\n";
  bfs(v);
}