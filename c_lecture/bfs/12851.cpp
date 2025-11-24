#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100000;
// distances 배열을 -1으로 초기화
vector<int> distances(MAX + 1, -1);
// ways 배열을 0으로 초기화
vector<int> ways(MAX + 1, 0);

int main(void) {
  int n, k;
  cin >> n >> k;

  // 시작 정점 세팅
  queue<int> q;
  q.push(n);
  distances[n] = 0;
  ways[n] = 1;

  // bfs 수행
  while (!q.empty()) {
    int x = q.front();
    q.pop();

    // 다음에 이동할 수 있는 위치들
    int next_positions[3] = {x - 1, x + 1, x * 2};
    for (int next : next_positions) {
      if (next < 0 || next > MAX) continue;

      // next 위치가 처음 방문하는 위치인 경우
      // 최단 거리 갱신
      if (distances[next] == -1) {
        distances[next] = distances[x] + 1;
        ways[next] = ways[x];
        q.push(next);
      }

      // 같은 최단 거리인 경우
      else if (distances[next] == distances[x] + 1) {
        ways[next] += ways[x];
      }
    }
  }

  cout << distances[k] << '\n' << ways[k] << '\n';
  return 0;
}