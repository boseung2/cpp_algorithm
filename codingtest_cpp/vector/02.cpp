#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a, int b) {
  return a>b;
}

vector<int> solution(vector<int> list) {
  sort(list.begin(), list.end(), compare);
  list.erase(unique(list.begin(), list.end()), list.end());

  return list;
}

void print(vector<int> list) {
  for(int x : list) {
    cout << x;
  }
  cout << endl;
}

int main(void) {
  print(solution({4, 2, 2, 1, 3, 4}));
  print(solution({2, 1, 1, 3, 2, 5, 4}));
}