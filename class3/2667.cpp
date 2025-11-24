#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int graph[25][25];
bool visited[25][25];
vector<int> village;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void) {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      graph[i][j] = row[j] - '0';
    }
  }

  // bfs로 단지 개수 센다.
  // 한 개 단지 안에 몇개 집 센다.
  // 다 세면 village에 push 한다.

  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == 1 && !visited[i][j]) {
        int cnt = 0;
        q.push({i, j});
        visited[i][j] = true;
        cnt++;

        while (!q.empty()) {
          auto cur = q.front();
          q.pop();
          int cx = cur.first;
          int cy = cur.second;

          for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (graph[nx][ny] == 0) continue;
            if (visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
            cnt++;
          }
        }
        village.push_back(cnt);
      }
    }
  }

  sort(village.begin(), village.end());

  cout << village.size() << "\n";
  for (int num : village) {
    cout << num << "\n";
  }
}