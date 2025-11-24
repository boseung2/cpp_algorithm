#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<long long> dist;
vector<int> pre;
vector<bool> visited;

int main(void) {
  int n, m;
  cin >> n >> m;
  graph.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    graph[x].push_back({y, w});
  }

  int r, t;
  cin >> r >> t;

  dist.assign(n + 1, 100000);
  pre.assign(n + 1, 0);
  visited.assign(n + 1, false);

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>
      pq;
  dist[r] = 0;
  pq.push({0, r});

  while (!pq.empty()) {
    long long cd = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (visited[u]) continue;
    visited[u] = true;

    for (auto& edge : graph[u]) {
      int v = edge.first;
      int w = edge.second;

      if (!visited[v] && cd + w < dist[v]) {
        dist[v] = cd + w;
        pre[v] = u;
        pq.push({dist[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << pre[i];
    if (i != n) cout << ' ';
  }
  cout << ' ';

  if (dist[t] == 100000) {
    cout << "Impossible\n";
  } else {
    cout << dist[t] << "\n";
  }
}