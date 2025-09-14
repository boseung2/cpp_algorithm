#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> point(n);
  for(int i=0; i<n; i++) {
    cin >> point[i].first >> point[i].second;
  }

  // second끼리 비교해서 가 더 작으면 앞으로
  // second 같을때 first 더 작으면 앞으로
  sort(point.begin(), point.end(), [](const pair<int, int> &a, const pair<int, int> &b){
    if(a.second != b.second) {
      return a.second < b.second;
    } else {
      return a.first< b.first;
    }
  });

  for(int i=0; i<n; i++) {
    cout << point[i].first << " " << point[i].second << "\n";
  } 
}