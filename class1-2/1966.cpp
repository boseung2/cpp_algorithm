#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void find(vector<int>& arr, int n, int m) {
  // arr을 queue에 넣는다.
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    q.push({arr[i], i});
  }
  // 뒤에 자기보다 높은 문서가 있는지 확인한다.
  int count = 0;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    bool hasBigger = false;
    int size = q.size();

    // 남아있는 문서들을 넣었다 빼면서 중요도가 더 큰 문서가 있는지 확인한다.
    for (int i = 0; i < size; i++) {
      auto next = q.front();
      q.pop();

      if (next.first > cur.first) {
        hasBigger = true;
      }
      q.push(next);
    }

    // 자기보다 중요도가 더 큰 문서가 있으면 다시 큐에 넣는다.
    if (hasBigger) {
      q.push(cur);
    } else {
      // 중요도가 제일 크면 count++
      count++;
      // 찾는 문서가 맞으면 count 출력하고 종료
      if (cur.second == m) {
        cout << count << "\n";
        return;
      }
    }
  }
}

int main(void) {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }
    find(arr, n, m);
  }

  return 0;
}