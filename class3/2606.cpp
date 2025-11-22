#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int cnt = 0;

int main(void) {
  int computer, pair;
  cin >> computer >> pair;

  graph.resize(computer + 1);
  visited.resize(computer + 1, false);

  for (int i = 0; i < pair; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  queue<int> q;
  q.push(1);
  visited[1] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (int next : graph[cur]) {
      if (!visited[next]) {
        visited[next] = true;
        cnt++;
        q.push(next);
      }
    }
  }

  cout << cnt << "\n";
  return 0;
}