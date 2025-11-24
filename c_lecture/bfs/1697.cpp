#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100000;
// visited 배열을 false로 초기화
vector<bool> visited(MAX + 1, false);
// dist 배열을 0으로 초기화
vector<int> dist(MAX + 1, 0);

int main(void) {
  int n, k;
  cin >> n >> k;

  // 시작 정점 세팅
  queue<int> q;
  q.push(n);
  visited[n] = true;
  dist[n] = 0;

  // bfs 수행
  while (!q.empty()) {
    int x = q.front();
    q.pop();

    // 목표 도달
    if (x == k) {
      cout << dist[x] << '\n';
      break;
    }

    // 다음에 이동할 수 있는 위치들
    int next_positions[3] = {x - 1, x + 1, x * 2};
    for (int next : next_positions) {
      if (next >= 0 && next <= MAX && !visited[next]) {
        visited[next] = true;
        dist[next] = dist[x] + 1;
        q.push(next);
      }
    }
  }
}