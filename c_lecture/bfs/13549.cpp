#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;
// dist 배열을 0으로 초기화
vector<int> dist(MAX + 1, 0);

int main(void) {
  int n, k;
  cin >> n >> k;

  // 시작 정점 세팅
  deque<int> dq;
  dq.push_back(n);
  dist[n] = 0;

  // bfs 수행
  while (!dq.empty()) {
    int x = dq.front();
    dq.pop_front();

    // 순간이동 하는 경우 (비용 0)
    int next = x * 2;
    if (next >= 0 && next <= MAX && dist[next] > dist[x]) {
      dist[next] = dist[x];
      dq.push_front(next);
    }

    // 1초 이동 : x - 1
    next = x - 1;
    if (next >= 0 && next <= MAX && dist[next] > dist[x] + 1) {
      dist[next] = dist[x] + 1;
      dq.push_back(next);
    }

    // 1초 이동 : x + 1
    next = x + 1;
    if (next >= 0 && next <= MAX && dist[next] > dist[x] + 1) {
      dist[next] = dist[x] + 1;
      dq.push_back(next);
    }
  }
  cout << dist[k] << "\n";
  return 0;
}