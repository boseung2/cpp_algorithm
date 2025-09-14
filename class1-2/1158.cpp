#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void) {
  int n;
  int k;
  cin >> n >> k;

  // queue에 넣는다.
  queue<int> q;
  for(int i=0; i<n; i++) {
    q.push(i+1);
  }

  // q 1개 남을때 까지 반복
  // k번째가 아니면 pop, push
  // k번째이면 pop
  vector<int> answer;
  while(q.size() > 1) {
    for(int i=0; i<k-1; i++) {
      q.push(q.front());
      q.pop();
    }
    answer.push_back(q.front());
    q.pop();
  }

  cout << "<";
  for(int x : answer) {
    cout << x << ", ";
  }
  cout << q.front();
  cout << ">";
}