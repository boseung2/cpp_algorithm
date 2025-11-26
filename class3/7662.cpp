#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int k;
    cin >> k;

    // 최대 힙, 최소 힙
    priority_queue<pair<int, int>> maxPQ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ;

    // 각 삽입 연산마다 부여되는 id가 살아있는지 표시
    vector<bool> alive(k, false);

    for (int i = 0; i < k; ++i) {
      char cmd;
      int n;
      cin >> cmd >> n;

      if (cmd == 'I') {
        // 값 n을 id=i와 함께 두 힙에 모두 삽입
        maxPQ.push({n, i});
        minPQ.push({n, i});
        alive[i] = true;
      } else if (cmd == 'D') {
        if (n == 1) {
          // 최대값 삭제: 이미 죽은 노드들 먼저 정리
          while (!maxPQ.empty() && !alive[maxPQ.top().second]) {
            maxPQ.pop();
          }
          if (!maxPQ.empty()) {
            alive[maxPQ.top().second] = false;
            maxPQ.pop();
          }
        } else if (n == -1) {
          // 최소값 삭제: 이미 죽은 노드들 먼저 정리
          while (!minPQ.empty() && !alive[minPQ.top().second]) {
            minPQ.pop();
          }
          if (!minPQ.empty()) {
            alive[minPQ.top().second] = false;
            minPQ.pop();
          }
        }
      }
    }

    // 출력 전에 한 번 더 양쪽 힙 정리
    while (!maxPQ.empty() && !alive[maxPQ.top().second]) {
      maxPQ.pop();
    }
    while (!minPQ.empty() && !alive[minPQ.top().second]) {
      minPQ.pop();
    }

    if (maxPQ.empty() || minPQ.empty()) {
      cout << "EMPTY\n";
    } else {
      cout << maxPQ.top().first << ' ' << minPQ.top().first << '\n';
    }
  }

  return 0;
}