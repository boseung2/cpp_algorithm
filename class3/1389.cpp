#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> dist;

int main(void) {
  int n, m;
  cin >> n >> m;

  graph.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int answer = -1;
  int minSum = 100000000;
  for (int i = 1; i <= n; i++) {
    dist.assign(n + 1, -1);
    queue<int> q;
    q.push(i);
    dist[i] = 0;

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next : graph[cur]) {
        if (dist[next] == -1) {
          dist[next] = dist[cur] + 1;
          q.push(next);
        }
      }
    }

    int sum = 0;
    for (int v = 1; v <= n; v++) {
      sum += dist[v];
    }

    if (sum < minSum) {
      minSum = sum;
      answer = i;
    }
  }

  cout << answer << "\n";
}