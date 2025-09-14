#include<iostream>
#include<vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  pair<int, int> p[n];
  vector<int> rank(n, 1);
  for(int i=0; i<n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  // 첫번째 부터 돌면서 모든 경우의 수를 다 센다.
  // 덩치가 더 큰 개수를 센다.
  // 덩치가 더 큰 개수 + 1 은 자신의 등수
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      // 자신이 0번째면 0~n중에 0빼고
      // 자신이 1이면, 0~n중에 1빼고
      if(i == j) continue;
      if(p[i].first < p[j].first && p[i].second < p[j].second) {
        rank[i]++;
      }
    }
  }

  for(int i=0; i<n; i++) {
    cout << rank[i] << (i + 1 == n ? '\n' : ' ');
  }
}