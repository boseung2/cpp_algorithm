#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<pair<int, string>> users(n);
  for(int i=0; i<n; i++) {
    cin >> users[i].first >> users[i].second;
  }

  // 첫번째로 나이 순 정렬
  // 두 번째로 먼저 가입한 순서로 정렬
  stable_sort(users.begin(), users.end(), 
    [](const pair<int,string> &a,const pair<int,string> &b){return a.first < b.first;});

  for(int i=0; i<n; i++) {
    cout << users[i].first << " " << users[i].second << "\n";
  }
}