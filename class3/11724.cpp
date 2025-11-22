#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
int cnt;

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : graph[cur]) {
      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }
}

int main(void) {
  int n, m;
  cin >> n >> m;

  graph.resize(n + 1);
  visited.resize(n + 1, false);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      bfs(i);
      cnt++;
    }
  }

  cout << cnt << "\n";
}